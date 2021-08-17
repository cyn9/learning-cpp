#include <iostream>

int main() {
    int number {0};
    std::cout << "Enter a number >> ";
    std::cin >> number;

    // Lambda expression here is self-referential.
    auto f = [](auto&& self, int n) -> int { 
        return (n < 2) ? 1 : n * self(self, n-1);
    };

    std::cout << number << "! = " << f(f, number) << '\n';
    return 0;
}
