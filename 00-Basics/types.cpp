#include <iostream>
#include <typeinfo>

int main() {
    int value;
    std::string str;

    // typeid example:
    std::cout << typeid(value).name() << std::endl;
    std::cout << typeid(str).name() << std::endl;

    // decltype example:
    decltype(value) number {100};
    decltype(str) text {"Hello, C++."};

    std::cout << typeid(number).name() << std::endl;
    std::cout << typeid(text).name() << std::endl;

    std::cout << number << std::endl;
    std::cout << text << std::endl;

    return 0;
}
