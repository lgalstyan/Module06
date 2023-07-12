#include "ScalarConverter.hpp"

int ScalarConverter::_intt = 0;
double ScalarConverter::_doublet = 0;
float ScalarConverter::_floatt = 0;
char ScalarConverter::_chart = '0';
double ScalarConverter::_literal = 0;
inf_type ScalarConverter::_type = DEFAULT;
std::string ScalarConverter::_value = "0";

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
    (void)rhs;
    return (*this);
}

bool ScalarConverter::checkInt()
{
    if (_value.empty() || (!std::isdigit(_value[0]) && _value[0] != '-' && _value[0] != '+'))
        return false;
    if (_value.find('.') != std::string::npos)
        return false;
    _intt = static_cast<int>(_literal);
    _doublet = static_cast<double>(_literal);
    _floatt = static_cast<float>(_literal);
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
    _intt = static_cast<char>(_literal);
    _doublet = static_cast<double>(_literal);
    _floatt = static_cast<float>(_literal);
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
    _intt = static_cast<int>(_literal);
    _doublet = static_cast<double>(_literal);
    _floatt = static_cast<float>(_literal);
    _chart =  static_cast<char>(_intt);
    return true;
}

void ScalarConverter::GetTypeInf()
{
    if (_value == "nan" || _value == "nanf")
        _type = NOT_A_NUMBER;
    else if(_value == "inf" || _value == "inff")
        _type = PLUS_INFINITY;
    else if(_value == "-inf" || _value == "-inff")
        _type = MIN_INFINITY;
}

void ScalarConverter::castChar()
{
    if (_value.size() == 1)
    {
        _chart = _value[0];
        _intt = static_cast<int>(_value[0]);
        _doublet = static_cast<double>(_value[0]);
        _floatt = static_cast<float>(_value[0]);
    }
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

    if (endPtr != value && (*endPtr == '\0' || value[strlen(value) - 1] == 'f'))
    {
        while (std::isspace(*endPtr))
            ++endPtr;
        if (*endPtr == '\0' || value[strlen(value) - 1] == 'f')
        return true;
            return false;
    }
    return false;
}

void ScalarConverter::print()
{
    std::cout << "char: ";
    if (std::isprint(_chart))
    std::cout << "\'" << _chart << "\'" << std::endl;
    else
        std::cout << "Non displayable.\n";
    std::cout << "int: ";
    std::cout << _intt << std::endl;
    std::cout << "float: ";
    if (_value.find('.') == std::string::npos || _literal == floor(_literal))
        std::cout << _floatt << ".0f" << std::endl;
    else
        std::cout << _floatt << "f" << std::endl;
    std::cout << "double: ";
    if (_value.find('.') == std::string::npos || _literal == floor(_literal))
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
    GetTypeInf();
    if (_type != DEFAULT)
    {
        print_inf();
    }
    else if (_literal == 0 && (_value.find('.') != std::string::npos || _value.size() > 1))
    {
        throw UnknownTypeException();
    }
    else if (_literal == 0 && input[0] != '0')
    {
        castChar();
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
