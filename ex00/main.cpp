#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    // ScalarConverter converter;
    double a;
    char szOrbits[] = "nan";
    //inf || -inf || nan => inf -inf nan 
    char *end = NULL;
    a = strtod(szOrbits, &end);
    std::cout << a << std::endl;
    try
    {
        if (argc != 2)
            std::cerr << KCYN << "Convertor takes 1 parameter\n" << RESET;
        else
            std::cout << YELLOW << "Convertor\n" << RESET;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}
