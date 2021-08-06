#include <iostream>

int main() {
    int number {3};
    std::cout << number << '\n';

    // Pass number variable to the lambda by value.
    // Variable number passed to the lambda just as it
    // is being copied. The value of its copy inside
    // the lambda can change but the original local 
    // value will remain unaffected.
    auto foo = [number]() mutable -> void {
        number = 5;
        std::cout << number << '\n';
    };

    foo();

    std::cout << number << '\n';

    return 0;
}
