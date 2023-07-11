#include "ScalarConverter.hpp"

int ScalarConverter::_intt = 0;
double ScalarConverter::_doublet = 0;
float ScalarConverter::_floatt = 0;
char ScalarConverter::_chart = '0';
double ScalarConverter::_literal = 0;
inf_type ScalarConverter::_type = DEFAULT;
std::string ScalarConverter::_value = "0";

ScalarConverter::ScalarConverter()
{
    _type = DEFAULT; 
}

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

bool ScalarConverter::checkInt()
{
    if (_value.empty() || (!std::isdigit(_value[0]) && _value[0] != '-' && _value[0] != '+'))
        return false;
    if (_value.find('.') != std::string::npos)
        return false;
    _intt = _literal;
    _doublet = _literal * 1.0;
    _floatt = _literal * 1.0;
    _chart =  static_cast<char>(_literal);
    return true;
}

bool ScalarConverter::checkFloat()
{
    if (_value.empty() || (!std::isdigit(_value[0]) && _value[0] != '-' && _value[0] != '+'))
        return false;
    if (_value.find('.') == std::string::npos)
        return false;
    if (_value.size() > 1 && _value[0] == '0' && _value[1] != '.')
        return false;
    size_t idx = _value.find('f');
    if (idx == std::string::npos || _value.size() != idx + 1)
        return false;
    int tmp = floor(_literal);
    _intt = tmp;
    _doublet = _literal;
    _floatt = _literal;
    _chart =  static_cast<char>(_intt);
    return true;
}

bool ScalarConverter::checkDouble()
{
    if (_value.empty() || (!std::isdigit(_value[0]) && _value[0] != '-' && _value[0] != '+'))
        return false;
    if (_value.find('.') == std::string::npos)
        return false;
    if (_value.size() > 1 && _value[0] == '0' && _value[1] != '.')
        return false;
    if (_value.find('f') != std::string::npos)
        return false;
    // std::cout << _literal << " " << _value;
    int tmp = floor(_literal);
    _intt = tmp;
    _doublet = _literal;
    _floatt = _literal;
    _chart =  static_cast<char>(_intt);
    return true;
}

void ScalarConverter::castChar()
{
    if (_value.size() == 1)
    {
        _chart = _value[0];
        _intt = static_cast<int>(_value[0]);
        _doublet = _intt * 1.0;
        _floatt = _intt * 1.0;
    }
    else if (_value == "nan")
        _type = NOT_A_NUMBER;
    else if(_value == "inf")
        _type = PLUS_INFINITY;
    else if(_value == "-inf")
        _type = MIN_INFINITY;
    else
        throw UnknownTypeException();
}

void ScalarConverter::print_inf()
{
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    if (_type == 0)
    {
        std::cout << "float: inff\n";
        std::cout << "double: inf\n";
        return ;
    }
    if (_type == 1)
    {
        std::cout << "float: -inf\n";
        std::cout << "double: -inff\n";
        return ;
    }
    if (_type == 2)
    {
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
        return ;
    }
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
}

bool ScalarConverter::isNumber(char *value)
{
    char* endPtr;
    strtod(value, &endPtr);

    if (endPtr != value && *endPtr == '\0')
    {
        while (std::isspace(*endPtr))
            ++endPtr;
        return *endPtr == '\0';
    }
    return false;
}

void ScalarConverter::print()
{
    std::cout << "char: ";
    if (std::isprint(_chart))
    std::cout << _chart << std::endl;
    else
        std::cout << "Non displayable.\n";
    std::cout << "int: ";
    std::cout << _intt << std::endl;
    std::cout << "float: ";
    if (_value.find('.') == std::string::npos)
        std::cout << _floatt << ".0f" << std::endl;
    else
        std::cout << _floatt << "f" << std::endl;
    std::cout << "double: ";
    if (_value.find('.') == std::string::npos)
        std::cout << _doublet << ".0" << std::endl;
    else
        std::cout << _doublet << std::endl;
}

void ScalarConverter::convert(char *input)
{
    if (input == NULL)
        return ;
    _value = input;
    char *end;
    _literal = strtod(input, &end);
        // std::cout << "input " << input << ", " << _literal;
    if (_literal == 0 && _value.find('.') != std::string::npos)
    {
        throw UnknownTypeException();
    }
    else if (_literal == 0 && input[0] != '0')
    {
        castChar();
        if (_type != 3)
            print_inf();
        else
            print();
    }
    else if (isNumber(input) && (checkInt() || checkDouble() || checkFloat()))
    {
        print();
    }
    else
    {
        throw UnknownTypeException();
    }
}   

const char* ScalarConverter::UnknownTypeException::what() const throw()
{
    return ("Exception: Unknown type");
}
