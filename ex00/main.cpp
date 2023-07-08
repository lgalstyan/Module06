#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    // ScalarConverter converter;
    if (argc != 2)
        std::cerr << KCYN << "Convertor takes 1 parameter\n" << RESET;
    else
        std::cout << YELLOW << "Convertor\n" << RESET;
    return (0);
}
