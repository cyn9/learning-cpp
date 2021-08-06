#include <iostream>

// Accepts function pointers as an argument.
void test(void (*pFunc)()) {
    pFunc();
}

int main() {
    auto func = []() { std::cout << "Hello, C++.\n"; }; // Returns void.

    func();     // Using lambda directly.
    test(func); // Passing lambda to a function.

    // Pass lambda expression directly to a function as an argument:
    test( []() { std::cout << "Hello again, C++.\n"; } );
    
    return 0;
}
