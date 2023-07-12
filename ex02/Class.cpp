#include "Class.hpp"

Base::~Base() {}

Base * generate(void)
{
    srand(time(NULL));
    int random = rand();
    if (random % 3 == 2)
    {
        return (new A);
    }
    else if (random % 3 == 1)
    {
        return (new B);
    }
    return (new C);
}


void identify(Base* p)
{
    A* a_type;
    a_type = dynamic_cast<A*>(p);
    if (a_type)
    {
        std::cout << BLUE << "The actual type of the object is A\n" << RESET; 
        // return ;
    }
    B* b_type;
    b_type = dynamic_cast<B*>(p);
    if (b_type)
    {
        std::cout << BLUE << "The actual type of the object is B\n" << RESET; 
        // return ;
    }
    C* c_type;
    c_type = dynamic_cast<C*>(p);
    if (c_type)
    {
        std::cout << BLUE << "The actual type of the object is C\n" << RESET; 
        // return ;   
    }
}


void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << BLUE << "The actual type of the object is A\n" << RESET;
    }
    catch(...) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << BLUE << "The actual type of the object is B\n" << RESET;
    }
    catch(...) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << BLUE << "The actual type of the object is C\n" << RESET;
    }
    catch(...) {}
}