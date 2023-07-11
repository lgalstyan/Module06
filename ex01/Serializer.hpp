#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include <iostream>

struct Data
{
    std::string firstName;
    std::string lastName;
    int age;
};

class Serializer 
{
    public:
        Serializer();
        Serializer(const Serializer& );
        Serializer& operator=(const Serializer& );
        ~Serializer();
        
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif