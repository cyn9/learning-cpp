#include <iostream>
#include <string>

void test_greet_func(void (*pFunc)(std::string), std::string text) {
    pFunc(text);
}

int main() { 
    // Demo 1: Lambda parameters:
    // Parenthesis are for passing arguments to the lambda.
    auto greetFunc = [](std::string name) -> void { 
        std::cout << "Hello, " << name << '\n'; 
    };

    greetFunc("C++.");
    test_greet_func(greetFunc, "C++.");

    std::cout << std::endl;

    // Demo 2: Lambda return types:
    // Addition example:
    auto add = [](int a, int b) -> int { return a + b; };
    std::cout << add(3, 5) << std::endl;

    // Division example:
    auto divide = [](double x, double y) -> double {
        // If there are different return types inside the lambda, 
        // C++ cannot automatically infer the return type of the 
        // output. In this case, if y is zero then it returns 0
        // which is an integer. Therefore, the return type in the
        // lambda must be stated explicitly.
        if (y == 0)
            return 0;
        
        return x / y;
    };

    std::cout << divide(12.5, 5.0) << '\n';
    std::cout << divide(3.4, 0) << '\n';

    return 0;
}
