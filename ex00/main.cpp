#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    ScalarConverter converter;
    try
    {
        if (argc != 2)
            std::cerr << KCYN << "Convertor takes one parameter\n" << RESET;
        else
        {
            std::cout << GREEN;
            converter.convert(argv[1]);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << RED <<  e.what()<< RESET << '\n';
    }
    return (0);
}
