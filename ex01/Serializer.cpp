#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer& other)
{
    (void)other;
}

Serializer& Serializer::operator=(const Serializer& rhs)
{
    (void)rhs;
    return *this;
}

Serializer::~Serializer(){}
