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
    if (_literal.empty() || (!std::isdigit(_literal[0]) && _literal[0] != '-' && _literal[0] != '+'))
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

static void ScalarConverter::FindType()
{
    if(checkChar())
        _type = 1;
    if(checkInt())
        _type = 2;
    if(checkFloat())
        _type = 3;
    if(checkDouble())
        _type = 4;
    _type = 5;
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
