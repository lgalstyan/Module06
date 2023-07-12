#include "Class.hpp"

int main()
{
    //-----------------------Test1------------------------
    std::cout << GREEN << "----------------------------Test1----------------------------\n" << RESET;
    Base* first = generate();
    Base* second = generate();

    std::cout << "Random type (pointer)" << BLUE << " => ";
        identify(*first);
    std::cout << RESET;
    std::cout << "Random type (referance)" << BLUE << " => ";
        identify(first);
    std::cout << RESET;
    delete first;

    std::cout << "Random type (pointer)" << BLUE << " => ";
        identify(*second);
    std::cout << RESET;
    std::cout << "Random type (referance)" << BLUE << " => ";
        identify(second);
    std::cout << RESET << std::endl;
    delete second;

    //-----------------------Test2----------------------------

    std::cout << GREEN << "----------------------Test2-----------------------\n" << RESET;
    Base* a = new A;
     std::cout << "Will print A" << BLUE << " => ";
        identify(*a);
    std::cout << RESET;
    std::cout << "Will print A" << BLUE << " => ";
        identify(a);
    std::cout << RESET;
    delete a; 

    Base* b= new B;
     std::cout << "Will print B" << BLUE << " => ";
        identify(*b);
    std::cout << RESET;
    std::cout << "Will print B" << BLUE << " => ";
        identify(b);
    std::cout << RESET;
    delete b;

    Base* c = new C;
     std::cout << "Will print C" << BLUE << " => ";
        identify(*c);
    std::cout << RESET;
    std::cout << "Will print C" << BLUE << " => ";
        identify(c);
    std::cout << RESET;
    delete c; 
}