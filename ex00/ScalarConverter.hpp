#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#define RED		"\033[31m"
#define RESET	"\033[0m"
#define BLUE	"\033[1;34m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define KMAG    "\x1B[35m"
#define KCYN    "\x1B[36m"

#include "iostream"

class ScalarConverter
{
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& );
        ScalarConverter& operator=(const ScalarConverter& );
        ~ScalarConverter();

        static void convert(std::string );

    private:

};

#endif