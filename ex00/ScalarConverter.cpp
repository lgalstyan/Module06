#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    _type = DEFAULT; 
}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    // *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
    // if (this != &rhs)
    // {
    //     _literal = rhs._literal;
    //     _type = rhs._type;
    //     _value = rhs._value;
    // }
    return (*this);
}

// static bool ScalarConverter::checkChar()
// {
//     if (_value.size() == 1 && !std::isdigit(_value[0]) && std::isprint(_value[0]))
//         return (true);
//     return (false);
// }

bool ScalarConverter::checkInt()
{
    if (_value.empty() || (!std::isdigit(_value[0]) && _value[0] != '-' && _value[0] != '+'))
        return false;

    std::istringstream iss(_literal);
    int value;
    char remainingChar;
    if (!(iss >> value) || iss.get(remainingChar))
        return false;
    _intt = _literal;
    _doublet = _literal * 1.0;
    _floatt = _literal * 1.0;
    _chart =  static_cast<char>(_literal);
    return true;
}

bool ScalarConverter::checkFloat() 
{
    
}

bool ScalarConverter::checkDouble()
{

}

char ScalarConverter::castChar()
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

// static int ScalarConverter::castInt()
// {

// }

// static float ScalarConverter::castFloat()
// {

// }

// static double ScalarConverter::castDouble()
// {

// }

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
}

void ScalarConverter::print()
{
    if (std::isprint(_chart))
    std::cout << "char: ";
    std::cout << _chart << std::endl;
    std::cout << "int: ";
    std::cout << _intt << std::endl;
    std::cout << "float: ";
    std::cout << _floatt << "f" << std::endl;
    std::cout << "double: ";
    std::cout << _doublet << std::endl;
}

void ScalarConverter::convert(char *input)
{
    if (input == NULL)
        return ;
    _value = input;
    char *end = NULL;
    _literal = strtod(input, &end);
    if (_literal == 0 && input[0] != '0')
    {
        castChar();
        if (_type != 3)
            print_inf();
        else
            print();
    }
    else if (checkInt())
    {
        print();
    }
    else if (checkFloat())
    {
        print();
    }
    //write for int, double, float
    // else if()
    // {

    // }
}   

const char* ScalarConverter::UnknownTypeException::what() const throw()
{
    return ("Exception: Unknown type\n");
}
