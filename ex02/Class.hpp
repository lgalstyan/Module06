#ifndef CLASS_HPP
#define CLASS_HPP

#define RESET	"\033[0m"
#define BLUE	"\033[1;34m"
#define GREEN   "\x1B[32m"

#include <ctime>
#include <iostream>

class Base
{
    public:
        virtual ~Base();
};

class A : public Base {};

class B :public Base {};

class C :public Base {};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif