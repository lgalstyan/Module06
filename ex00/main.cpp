#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    // ScalarConverter converter;
    // double a;
    // char szOrbits[] = "";
    // char *end = NULL;
    // a = strtod(szOrbits, &end);
    // std::cout << a << std::endl;
    if (argc != 2)
        std::cerr << KCYN << "Convertor takes 1 parameter\n" << RESET;
    else
        std::cout << YELLOW << "Convertor\n" << RESET;
    return (0);
}
