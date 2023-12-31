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
#include <cmath>
enum inf_type
{
    PLUS_INFINITY = 0,
    MIN_INFINITY = 1,
    NOT_A_NUMBER = 2,
    DEFAULT = 3
};

class ScalarConverter
{
    public:
        static void convert(char *);

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& );
        ScalarConverter& operator=(const ScalarConverter& );
        ~ScalarConverter();

        static void print();
        static void print_inf();
        
        static void castChar();
        static void GetTypeInf();

        static bool isNumber(char* );
        static bool checkInt();
        static bool checkFloat();
        static bool checkDouble();

        static int _intt;
        static double _doublet;
        static char _chart;
        static float _floatt;

        static double _literal;
        static inf_type _type;
        static std::string _value;

        class UnknownTypeException : public std::exception
        {
            public:
                const char * what() const throw();
        };
};

#endif
