#include <iostream>
#include <cmath>

int main()
{

    double a;
    char szOrbits[] = "1.0f";
    char *end = NULL;
    a = strtod(szOrbits, &end);
    std::cout << a << std::endl;


    // char a = 'x';
    // double b = 1.6;
    // std::cout << a  << std::endl;
    // std::cout << static_cast<int>(b) << std::endl;

    // double number = 3.7;
    // double roundedDown = floor(number);
    
    // std::cout << "Original number: " << number << std::endl;
    // std::cout << "Rounded down: " << roundedDown << std::endl;
    // int a = 1;
    // std::cout << static_cast<float>(a) << std::endl;
    
    return (0);
}