import csv
import textwrap
import os
import re

top_level_namespace = "stm32"
reverse_bit_field_order = False

def to_camel_case(string):

    words = string.strip().split()
    camel_case = ''.join(word.strip().title() for word in words)
    camel_case = re.sub(r'\W+', '', camel_case)

    if camel_case[0].isdigit():
        camel_case = "_" + camel_case

    return camel_case

class RegisterFieldValue:

    def __init__(self, value, description):
        self.value = value
        self.description = description
        print(f"\tNew Value: {self.value} : {self.description}")

class RegisterField:

    def __init__(self, reg_long_name, reg_short_name, name, description, bit_position, width, access, type):
        self.reg_long_name = reg_long_name
        self.reg_short_name = reg_short_name
        self.type = type
        self.name = name
        self.description = description
        self.bit_position = bit_position
        self.width = width
        self.access = access
        self.values = []
        print(f" - [{reg_short_name}] New Field: Name={name}, Description={description}, Bit Position={str(bit_position)}, Width={width}, Access={access}, Type={type}")

    def add_value(self, value, description):
        self.values.append(RegisterFieldValue(value, description))

    def generate_method_name(self, prefix):
        return f"{prefix}_{self.reg_short_name}_{self.name}"

    def generate_data_type(self):

        if self.type is not None and self.type != "":
            return self.type
        else:
            return to_camel_case(self.description)

    def generate_enum(self):

        if ("RESERVED" in self.name):
            return ""
        elif (len(self.type.strip()) > 0):
            return ""

        base_type = ""

        if self.width <= 8:
            base_type = "uint8_t"
        elif self.width > 8 and self.width <= 16:
            base_type = "uint16_t"
        else:
            base_type = "uint32_t"

        output = (
            f"enum class {self.generate_data_type()} : {base_type}\n"
            f"{{\n"
        )

        if len(self.values) == 0:
            for i in range(0, (2 ** self.width)):
                output += f"\tValue{i} = {i}U,\n"
        else:
            for value in self.values:
                output += f"\t{to_camel_case(value.description)} = {str(value.value)}U,\n"

        output += f"}};\n\n"

        return output

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

    def __init__(self, long_name, short_name):
        self.long_name = long_name
        self.short_name = short_name
        self.fields = []
        print(f"New Register: Long Name={self.long_name}, Short Name={self.short_name}")

    def add_field(self, name, description, bit_position, width, access, type):
        self.fields.append(RegisterField(self.long_name, self.short_name, name, description, bit_position, width, access, type))

    def add_value_to_field(self, field_name, value, description):

        matching_field = [field for field in self.fields if field.name == field_name]

        if matching_field:
            matching_field[0].add_value(value, description)

    def generate_class_member_variable(self):
        return f"{self.long_name} {self.short_name};\n";

    def generate_enums(self):

        output = ""

        for field in self.fields:
            output += field.generate_enum()

        return output

    def generate_union(self):

        bits_used = 0
        number_of_reserved = 0

        output = (
            f"union {self.long_name}\n"
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

            if field.width == 1:
                bit_comment = f"{f'[{field.bit_position}]':6} {field.access:<3}: {field.description}"
            else:
                first_bit = field.bit_position
                last_bit = field.bit_position + field.width - 1
                bit_comment = f"{f'[{last_bit}:{first_bit}]':6} {field.access:<3}: {field.description}"

            output += f"\t\t{field.generate_data_type():<{data_type_length}} {field.name:<9} : {str(field.width)}; // {bit_comment}\n"
            bits_used += field.width

            if "RESERVED" in field.name:
                number_of_reserved += 1

        if bits_used < 32:
            output += f"\t\t{'uint32_t':<{data_type_length}} RESERVED{str(number_of_reserved + 1):<1} : {str(32 - bits_used)};\n"

        output += (
            f"\t}} Fields;\n"
            f"\tvolatile uint32_t Value;\n"
            f"}};\n"
        )

        return output

    def generate_getters_and_setters(self):
        
        output = f"// {self.short_name} Fields\n"

        for field in self.fields:
            if "r" in field.access:
                output += field.generate_getter()
        
        for field in self.fields:
            if "w" in field.access:
                output += field.generate_setter()

        return output
    
    def generate_virtual_getters_and_setters(self):
        
        output = f"// {self.short_name} Fields\n"

        for field in self.fields:
            if "r" in field.access:
                output += field.generate_virtual_getter()
        
        for field in self.fields:
            if "w" in field.access:
                output += field.generate_virtual_setter()

        return output
    
    def generate_mock_methods(self):

        output = f"\n// {self.short_name} Fields\n"

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

    def __init__(self, name):
        self.name = name
        self.registers = []

    def parse_registers_csv(self, file_name):
        
        print(f"Parsing CSV File: {file_name}")

        with open(file_name, 'r', encoding='utf-8-sig') as file:
            
            csv_reader = csv.reader(file)

            register = None
            register_long_name = ""
            register_short_name = ""

            for row in csv_reader:
                
                if row[0] != register_long_name:

                    register_long_name = row[0]
                    register_short_name = row[1]
                    register = Register(register_long_name, register_short_name)
                    self.registers.append(register)

                field_type = row[2]
                field_description = row[3]
                field_name = row[4]
                bit_position = int(row[5])
                width = int(row[6])
                access = row[7]

                register.add_field(field_name, field_description, bit_position, width, access, field_type)

    def lookup_register(self, register_name):
        
        matching_register = [register for register in self.registers if register.short_name == register_name]

        if matching_register:
            return matching_register[0]
        else:
            return None

    def parse_values_csv(self, file_name):

        print(f"Parsing CSV Values File: {file_name}")

        with open(file_name, 'r', encoding='utf-8-sig') as file:
            
            csv_reader = csv.reader(file)

            for row in csv_reader:

                register_short_name = row[0]
                field_name = row[1]
                value = int(row[2])
                description = row[3]

                matching_register = self.lookup_register(register_short_name)

                if matching_register is not None:
                    matching_register.add_value_to_field(field_name, value, description)

    def generate_enums(self):

        output = ""

        for register in self.registers:
            output += register.generate_enums()

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
        
        output += "\nprivate:\n\n"

        for register in self.registers:
            output += textwrap.indent(register.generate_class_member_variable(), "\t")

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

            header_guard    = os.path.basename(file_name).replace(".", "_").upper() + "_"
            enums           = textwrap.indent(self.generate_enums(), "\t")

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

spi = Peripheral("Spi")

spi.parse_registers_csv("spi_registers.csv")
spi.parse_values_csv("spi_register_values.csv")

spi.generate_types_header("../spi/spi_types.hpp")
spi.generate_header("../spi/spi_register_map.hpp")
spi.generate_unit_test_file("../test/spi/spi_register_map_test.cpp", "spi_register_map.hpp")
spi.generate_mock_file("../test/spi/spi_register_map_mock.hpp", "spi_register_map.hpp")