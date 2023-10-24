import csv
import textwrap
import os
import re
from typing import List

top_level_namespace = "stm32"
reverse_bit_field_order = False
register_size_in_bytes = 4

def to_camel_case(string):

    words = string.strip().split()
    camel_case = ''.join(word.strip().title() for word in words)
    camel_case = re.sub(r'\W+', '', camel_case)

    if camel_case[0].isdigit():
        camel_case = "_" + camel_case

    return camel_case

class EnumValue:

    value : int
    description : str

    def __init__(self, value, description):
        self.value = value
        self.description = description
        print(f"\tNew Value: {self.value} : {self.description}")

class EnumType:

    name : str
    enum_values : List[EnumValue]

    def __init__(self, name):
        self.name = name
        self.enum_values = []
        print(f"New Enum: {self.name}")

    def add_enum_value(self, value, description):
        self.enum_values.append(EnumValue(value, description))

    def generate(self):

        output = f"enum class {self.name} : uint8_t\n{{\n"

        for enum_value in self.enum_values:
            output += f"\t{to_camel_case(enum_value.description)} = {enum_value.value}U,\n"
        
        output += "};\n\n"

        return output

class RegisterField:

    def __init__(self, reg_name, name, description, bit_position, width, access, type):
        self.reg_long_name = reg_name
        self.reg_short_name = reg_name
        self.type = type
        self.name = name
        self.description = description
        self.bit_position = bit_position
        self.width = width
        self.access = access
        print(f" - [{reg_name}] New Field: Name={name}, Description={description}, Bit Position={str(bit_position)}, Width={width}, Access={access}, Type={type}")

    def generate_method_name(self, prefix):
        return f"{prefix}_{self.reg_short_name}_{self.name}"

    def generate_data_type(self):

        if self.type is not None and self.type != "":
            return self.type
        else:
            if self.width <= 8:
                return "uint8_t"
            elif self.width > 8 and self.width <= 16:
                return "uint16_t"
            else:
                return "uint32_t"

    def generate_getter(self):
        return f"{self.generate_data_type()} {self.generate_method_name('get')}() const override {{ return {self.reg_short_name}.Fields.{self.name}; }}\n"

    def generate_setter(self):
        return f"void {self.generate_method_name('set')}({self.generate_data_type()} value) override {{ {self.reg_short_name}.Fields.{self.name} = value; }}\n"

    def generate_virtual_getter(self):
        return f"virtual {self.generate_data_type()} {self.generate_method_name('get')}() const = 0;\n"

    def generate_virtual_setter(self):
        return f"virtual void {self.generate_method_name('set')}({self.generate_data_type()} value) = 0;\n"

    def generate_mock_getter(self):
        return f"MOCK_CONST_METHOD0({self.generate_method_name('get')}, {self.generate_data_type()}());\n"

    def generate_mock_setter(self):
        return f"MOCK_METHOD1({self.generate_method_name('set')}, void({self.generate_data_type()} value));\n"

    def generate_unit_test(self):

        assigned_value = (2 ** self.width) - 1
        expected_value = assigned_value << self.bit_position

        return (
            f"TEST({self.reg_long_name}, {self.name})\n"
            f"{{\n"
            f"\t{self.reg_long_name} reg;\n"
            f"\treg.Value = 0U;\n"
            f"\treg.Fields.{self.name} = ({self.generate_data_type()}){assigned_value}U;\n"
            f"\tEXPECT_EQ(0x{format(expected_value, '08X')}U, reg.Value);\n"
            f"}}\n\n"
        )

class Register:

    name : str
    offset : int
    fields : List[RegisterField]

    def __init__(self, name, offset):
        self.name = name
        self.offset = offset
        self.fields = []
        print(f"New Register: Name={self.name}, Offset=0x{self.offset:X}")

    def add_field(self, name, description, bit_position, width, access, type):
        self.fields.append(RegisterField(self.name, name, description, bit_position, width, access, type))

    def generate_class_member_variable(self):
        return f"{self.name} {self.name}; // Address Offset 0x{self.offset:X}\n"

    def generate_union(self):

        bits_used = 0
        number_of_reserved = 0

        print(f"Generating union: {self.name}")

        output = (
            f"union {self.name}\n"
            f"{{\n"
            f"\tvolatile struct\n"
            f"\t{{\n"
        )
        
        self.fields.sort(key=lambda x: x.bit_position, reverse=reverse_bit_field_order)

        data_type_length = 0

        for field in self.fields:
            if len(field.generate_data_type()) > data_type_length:
                data_type_length = len(field.generate_data_type())

        for field in self.fields:

            bit_comment = ""

            if "reserved" in field.name.lower():
                number_of_reserved += 1
                field.name = "Reserved" + str(number_of_reserved)

            if field.width == 1:
                bit_comment = f"{f'[{field.bit_position}]':7} {field.access:<3}: {field.description}"
            else:
                first_bit = field.bit_position
                last_bit = field.bit_position + field.width - 1
                bit_comment = f"{f'[{last_bit}:{first_bit}]':7} {field.access:<3}: {field.description}"

            output += f"\t\t{field.generate_data_type():<{data_type_length}} {field.name:<11} : {str(field.width)}; // {bit_comment}\n"
            bits_used += field.width

        if bits_used < 32:
            output += f"\t\t{'uint32_t':<{data_type_length}} Reserved{str(number_of_reserved + 1):<3} : {str(32 - bits_used)}; // Pad to 32 bits \n"

        output += (
            f"\t}} Fields;\n"
            f"\tvolatile uint32_t Value;\n"
            f"}};\n"
        )

        return output

    def generate_getters_and_setters(self):
        
        output = f"// {self.name} Fields\n"

        for field in self.fields:
            if "r" in field.access:
                output += field.generate_getter()
        
        for field in self.fields:
            if "w" in field.access:
                output += field.generate_setter()

        return output
    
    def generate_virtual_getters_and_setters(self):
        
        output = f"// {self.name} Fields\n"

        for field in self.fields:
            if "r" in field.access:
                output += field.generate_virtual_getter()
        
        for field in self.fields:
            if "w" in field.access:
                output += field.generate_virtual_setter()

        return output
    
    def generate_mock_methods(self):

        output = f"\n// {self.name} Fields\n"

        for field in self.fields:
            if "r" in field.access:
                output += field.generate_mock_getter()
        
        for field in self.fields:
            if "w" in field.access:
                output += field.generate_mock_setter()

        return output

    def generate_unit_tests(self):

        output = ""

        for field in self.fields:
            output += field.generate_unit_test()

        return output

class Peripheral:

    name : str
    registers : List[Register]
    types : List[EnumType]

    def __init__(self, name):
        self.name = name
        self.registers = []
        self.types = []

    def lookup_register(self, register_name):
        
        matching_register = [register for register in self.registers if register.name == register_name]

        if matching_register:
            return matching_register[0]
        else:
            return None

    def parse_registers_csv(self, file_name):
        
        print(f"Parsing Registers CSV File: {file_name}")

        with open(file_name, 'r', encoding='utf-8-sig') as file:

            csv_reader = csv.reader(file)

            register = None
            name = ""

            for row in csv_reader:

                name = row[0]
                offset = int(row[1], 16)

                register = Register(name, offset)
                self.registers.append(register)

    def parse_register_fields_csv(self, file_name):
        
        print(f"Parsing Register Fields CSV File: {file_name}")

        with open(file_name, 'r', encoding='utf-8-sig') as file:
            
            csv_reader = csv.reader(file)

            for row in csv_reader:
            
                register_name = row[0]

                register = self.lookup_register(register_name)

                if register is None:
                    continue

                field_type = row[1]
                field_description = row[2]
                field_name = row[3]
                bit_position = int(row[4])
                width = int(row[5])
                access = row[6]

                register.add_field(field_name, field_description, bit_position, width, access, field_type)

    def parse_types_csv(self, file_name):

        print(f"Parsing CSV Types File: {file_name}")

        with open(file_name, 'r', encoding='utf-8-sig') as file:
            
            csv_reader = csv.reader(file)

            type_name = ""
            type : EnumType = None

            for row in csv_reader:

                if row[0] != type_name:

                    type_name = row[0]
                    type = EnumType(type_name)
                    self.types.append(type)
                
                enum_value = int(row[1])
                enum_description = row[2]

                type.add_enum_value(enum_value, enum_description)

    def generate_enums(self):

        output = ""

        for type in self.types:
            output += type.generate()

        return output

    def generate_unions(self):

        output = ""

        for register in self.registers:
            output += register.generate_union() + "\n"

        return output

    def generate_interface_class(self):

        output = (
            f"class I{self.name}RegisterMap\n"
            "{\n"
            "public:\n"
        )
        
        for register in self.registers:
            output += "\n" + textwrap.indent(register.generate_virtual_getters_and_setters(), "\t")
        
        output += "};\n\n"

        return output

    def generate_concrete_class(self):

        output = (
            f"class {self.name}RegisterMap : public I{self.name}RegisterMap\n"
            f"{{\n"
            f"public:\n"
        )
        
        for register in self.registers:
            output += "\n" + textwrap.indent(register.generate_getters_and_setters(), "\t")
        
        # Output the private member variables which are mapped to the memory locations
        # of the peripheral device registers.

        output += "\nprivate:\n\n"

        highest_register = max(self.registers, key=lambda register: register.offset)
        number_of_reserved = 0

        for offset in range(0, highest_register.offset + register_size_in_bytes, register_size_in_bytes):
            matching_register = [register for register in self.registers if register.offset == offset]

            if matching_register:
                output += textwrap.indent(matching_register[0].generate_class_member_variable(), "\t")
            else:
                number_of_reserved += 1
                output += f"\tuint32_t Reserved{number_of_reserved}; // Address Offset 0x{offset:X}\n"

        output += "};\n"

        return output

    def generate_mock_class(self):

        output = (
            f"class Mock{self.name}RegisterMap : public I{self.name}RegisterMap\n"
            f"{{\n"
            f"public:\n"
        )
        
        for register in self.registers:
            output += textwrap.indent(register.generate_mock_methods(), "\t")

        output += "};\n\n"

        return output

    def generate_unit_tests(self):

        output = ""

        for register in self.registers:
            output += register.generate_unit_tests()

        return output

    def generate_types_header(self, file_name):

        with open(file_name, 'w') as file:

            header_guard = os.path.basename(file_name).replace(".", "_").upper() + "_"
            enums        = textwrap.indent(self.generate_enums(), "\t")

            file.write(
                f"#ifndef {header_guard}\n"
                f"#define {header_guard}\n\n"
                f"#include <cstdint>\n\n"
                f"using namespace std;\n\n"
                f"namespace {top_level_namespace}::{self.name.lower()}\n"
                f"{{\n"
                f"{enums}"
                f"}}\n"
                f"#endif // {header_guard}"
            )

    def generate_header(self, file_name):

        with open(file_name, 'w') as file:
        
            header_guard    = os.path.basename(file_name).replace(".", "_").upper() + "_"
            unions          = textwrap.indent(self.generate_unions(), "\t")
            interface_class = textwrap.indent(self.generate_interface_class(), "\t")
            concrete_class  = textwrap.indent(self.generate_concrete_class(), "\t")

            file.write(
                f"#ifndef {header_guard}\n"
                f"#define {header_guard}\n\n"
                f"#include <cstdint>\n"
                f"#include \"{self.name.lower()}_types.hpp\"\n\n"
                f"using namespace std;\n\n"
                f"namespace {top_level_namespace}::{self.name.lower()}\n"
                f"{{\n"
                f"{unions}"
                f"{interface_class}"
                f"{concrete_class}"
                f"}}\n"
                f"#endif // {header_guard}"
            )
    
    def generate_unit_test_file(self, file_name, header_to_include):
        
        with open(file_name, 'w') as file:   
        
            unit_tests = self.generate_unit_tests()
        
            file.write(
                f"#include <gtest/gtest.h>\n"
                f"#include <gmock/gmock.h>\n"
                f"#include \"{header_to_include}\"\n\n"
                f"using namespace {top_level_namespace}::{self.name.lower()};\n\n"
                f"{unit_tests}"
            )
    
    def generate_mock_file(self, file_name, header_to_include):

        with open(file_name, 'w') as file:   
        
            mock_class = self.generate_mock_class()
        
            file.write(
                f"#include <gtest/gtest.h>\n"
                f"#include <gmock/gmock.h>\n"
                f"#include \"{header_to_include}\"\n\n"
                f"using namespace {top_level_namespace}::{self.name.lower()};\n"
                f"using namespace testing;\n\n"
                f"{mock_class}"
            )

peripheral_name = "rcc"

peripheral = Peripheral(to_camel_case(peripheral_name))

peripheral.parse_registers_csv(f"{peripheral_name}_registers.csv")
peripheral.parse_register_fields_csv(f"{peripheral_name}_register_fields.csv")
peripheral.parse_types_csv(f"{peripheral_name}_types.csv")

peripheral.generate_types_header(f"../{peripheral_name}/{peripheral_name}_types.hpp")
peripheral.generate_header(f"../{peripheral_name}/{peripheral_name}_register_map.hpp")
peripheral.generate_unit_test_file(f"../test/{peripheral_name}/{peripheral_name}_register_map_test.cpp", f"{peripheral_name}_register_map.hpp")
peripheral.generate_mock_file(f"../test/{peripheral_name}/{peripheral_name}_register_map_mock.hpp", f"{peripheral_name}_register_map.hpp")