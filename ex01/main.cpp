#include "Serializer.hpp"

int main() {
    
    Data data;
    data.age = 60;
    data.firstName = "Johnny";
    data.lastName = "Depp";

    uintptr_t sPtr = Serializer::serialize(&data);

    Data* dPtr = Serializer::deserialize(sPtr);

    if (dPtr == &data) {
        std::cout << "Deserialization successful. Pointers match." << std::endl;
        std::cout << "First name: " << dPtr->firstName << std::endl;
        std::cout << "Last name: " << dPtr->lastName << std::endl;
        std::cout << "Age: " << dPtr->age << std::endl;
    } else {
        std::cout << "Deserialization failed. Pointers do not match." << std::endl;
    }

    return 0;
}