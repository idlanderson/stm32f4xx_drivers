import csv
import textwrap

class RegisterField:

    def __init__(self, reg_long_name, reg_short_name, name, bit_position, width, access, type="uint32_t"):
        self.reg_long_name = reg_long_name
        self.reg_short_name = reg_short_name
        self.type = type
        self.name = name
        self.bit_position = bit_position
        self.width = width
        self.access = access

    def generate_method_name(self, prefix):
        return prefix + "_" + self.reg_short_name + "_" + self.name

    def generate_getter(self):
        return self.type + " " + self.generate_method_name("get") + "() const override { return " + self.reg_short_name + ".Fields." + self.name + "; }\n"

    def generate_setter(self):
        return "void " + self.generate_method_name("set") + "(" + self.type + " value) override { " + self.reg_short_name + ".Fields." + self.name + " = value; }\n"

    def generate_virtual_getter(self):
        return "virtual " + self.type + " " + self.generate_method_name("get") + "() const = 0;\n"

    def generate_virtual_setter(self):
        return "virtual void " + self.generate_method_name("set") + "(" + self.type + " value) = 0;\n"

    def generate_mock_getter(self):
        return "MOCK_CONST_METHOD0(" + self.generate_method_name("get") + ", " + self.type + "());\n"

    def generate_mock_setter(self):
        return "MOCK_METHOD1(" + self.generate_method_name("set") + ", void(" + self.type + " value));\n"

    def generate_unit_test(self):

        expected_value = 1 << self.bit_position

        output = "TEST(" + self.reg_long_name + ", " + self.name + ")\n" + \
            "{\n" + \
            "\t" + self.reg_long_name + " reg;\n" + \
            "\treg.Value = 0U;\n" + \
            "\treg.Fields." + self.name + " = (" + self.type + ")1U;\n" + \
            "\tEXPECT_EQ(0x" + format(expected_value, '08X') + "U, reg.Value);\n" + \
            "}\n"

        return output

class Register:

    def __init__(self, long_name, short_name):
        self.long_name = long_name
        self.short_name = short_name
        self.fields = []

    def add_field(self, name, bit_position, width, access, type):
        self.fields.append(RegisterField(self.long_name, self.short_name, name, bit_position, width, access, type))

    def generate_class_field(self):

        return self.long_name + " " + self.short_name + ";\n";

    def generate_union(self):

        bits_used = 0
        number_of_reserved = 0

        output = "union " + self.long_name + "\n" + \
                "{\n" + \
                "\tvolatile struct\n" + \
                "\t{\n"
        
        for field in self.fields:
            output += "\t\tuint32_t " + field.name + " : " + str(field.width) + ";\n"
            bits_used += field.width

            if "RESERVED" in field.name:
                number_of_reserved += 1

        if bits_used < 32:
            output += "\t\tuint32_t RESERVED" + str(number_of_reserved + 1) + " : " + str(32 - bits_used) + ";\n"

        output += "\t} Fields;\n" + \
            "\tvolatile uint32_t Value;\n" + \
            "};\n"

        return output

    def generate_getters_and_setters(self):
        
        output = "// " + self.short_name + " Fields\n"

        for field in self.fields:
            if "r" in field.access:
                output += field.generate_getter()
        
        for field in self.fields:
            if "w" in field.access:
                output += field.generate_setter()

        return output
    
    def generate_virtual_getters_and_setters(self):
        
        output = "// " + self.short_name + " Fields\n"

        for field in self.fields:
            if "r" in field.access:
                output += field.generate_virtual_getter()
        
        for field in self.fields:
            if "w" in field.access:
                output += field.generate_virtual_setter()

        return output
    
    def generate_mock_methods(self):

        output = "\n// " + self.short_name + " Fields\n"

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

    def parse_csv(self, file_name):
        # Open the CSV file
        with open(file_name, 'r', encoding='utf-8-sig') as file:
            # Create a CSV reader object
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
                field_name = row[3]
                bit_position = int(row[4])
                width = int(row[5])
                access = row[6]

                register.add_field(field_name, bit_position, width, access, field_type)

    def generate_unions(self):

        output = ""

        for register in self.registers:
            output += register.generate_union() + "\n"

        return output

    def generate_interface_class(self):

        output = "class I" + self.name + "RegisterMap\n" + \
            "{\n" + \
            "public:\n"
        
        for register in self.registers:
            output += "\n" + textwrap.indent(register.generate_virtual_getters_and_setters(), "\t")
        
        output += "};\n\n"

        return output

    def generate_concrete_class(self):

        output = "class " + self.name + "RegisterMap : public I" + self.name + "RegisterMap\n" + \
            "{\n" + \
            "public:\n"
        
        for register in self.registers:
            output += "\n" + textwrap.indent(register.generate_getters_and_setters(), "\t")
        
        output += "\nprivate:\n\n"

        for register in self.registers:
            output += textwrap.indent(register.generate_class_field(), "\t")

        output += "};\n"

        return output

    def generate_mock_class(self):

        output = "class Mock" + self.name + "RegisterMap : public I" + self.name + "RegisterMap\n" + \
            "{\n" + \
            "public:\n"
        
        for register in self.registers:
            output += textwrap.indent(register.generate_mock_methods(), "\t")

        output += "};\n\n"

        return output

    def generate_unit_tests(self):

        output = ""

        for register in self.registers:
            output += register.generate_unit_tests()

        return output

    def generate_header(self, file_name):

        with open(file_name, 'w') as file:   
        
            unions = textwrap.indent(self.generate_unions(), "\t")
            interface_class = textwrap.indent(self.generate_interface_class(), "\t")
            concrete_class = textwrap.indent(self.generate_concrete_class(), "\t")

            file.write("#include <cstdint>\n\n" + \
                "using namespace std;\n\n" + \
                "namespace stm32::" + self.name.lower() + "\n" + \
                "{\n" + \
                unions + \
                interface_class + \
                concrete_class + \
                "}")
    
    def generate_unit_test_file(self, file_name, header_to_include):
        
        with open(file_name, 'w') as file:   
        
            preamble = "#include <gtest/gtest.h>\n" + \
                "#include <gmock/gmock.h>\n" + \
                "#include \"" + header_to_include + "\"\n\n" + \
                "using namespace stm32::" + self.name.lower() + ";" + "\n" + \
                "using namespace testing;\n\n"
            
            mock_class = self.generate_mock_class()
            unit_tests = self.generate_unit_tests()

            file.write(preamble + \
                mock_class + \
                unit_tests)

spi = Peripheral("Spi")
spi.parse_csv("spi_registers.csv")
spi.generate_header("spi2.hpp")
spi.generate_unit_test_file("spi2_test.cpp", "spi2.hpp")