#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
    if (this != &rhs)
    {
        _literal = rhs._literal;
        _type = rhs._type;
        _value = rhs._value;
    }
    return (*this);
}

static bool ScalarConverter::checkChar()
{
    if (_value.size() == 1 && !std::isdigit(_value[0]) && std::isprint(_value[0]))
        return (true);
    return (false);
}

static bool ScalarConverter::checkInt()
{
    if (_literal.empty() || (!isdigit(_literal[0]) && _literal[0] != '-' && _literal[0] != '+'))
        return false;

    std::istringstream iss(_literal);
    int value;
    char remainingChar;
    if (!(iss >> value) || iss.get(remainingChar))
        return false;
    return true;
}

static bool ScalarConverter::checkFloat() 
{

}

static bool ScalarConverter::checkDouble()
{

}

static int ScalarConverter::FindType()
{
    if(checkChar())
        return (1);
    if(checkInt())
        return (2);
    if(checkFloat())
        return (3);
    if(checkDouble())
        return (4);
    return (5);
}

static void ScalarConverter::print()
{
    std::cout << "char: ";
    std::cout << castChar();
    std::cout << "int: ";
    std::cout << castInt();
    std::cout << "float: ";
    std::cout << castFloat();
    std::cout << "double: ";
    std::cout << castDouble();
}

static void ScalarConverter::convert(char *input)
{
    if (input == NULL)
        return ;
    char *end = NULL;
    _literal = strtod(input, &end);
    print();
}   
