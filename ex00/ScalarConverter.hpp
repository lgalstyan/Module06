#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#define RED		"\033[31m"
#define RESET	"\033[0m"
#define BLUE	"\033[1;34m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define KMAG    "\x1B[35m"
#define KCYN    "\x1B[36m"

#include <iostream>
#include <sstream>
/****************
 * type values:
 * 1 is char
 * 2 is int
 * 3 is float
 * 4 is double
 * 5 is inff
****************/

class ScalarConverter
{
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& );
        ScalarConverter& operator=(const ScalarConverter& );
        ~ScalarConverter();

        static void convert(char *);

    private:
        static int FindType();
        static void print();

        static char castChar();
        static int castInt();
        static float castFloat();
        static double castDouble();

        static bool checkChar();
        static bool checkInt();
        static bool checkFloat();
        static bool checkDouble();

        static double _literal;
        static int _type;
        static std::string _value;
};

#endif