#include <iostream>

int main() {
    int x {1};
    int y {2};
    int z {3};

    // Capture only x and y by reference:
    [&x, &y]() { std::cout << x << ", " << y << ".\n\n"; }();

    // Capture all local variables by value:
    [=]() { std::cout << x << ", " << y << ", " << z << ".\n\n"; }();

    // Capture all local variables by value, then capture variable y as reference:
    [=, &y]() { y = 10; std::cout << x << ", " << y << ", " << z << ".\n\n"; }();
    std::cout << "y has changed to " << y << ".\n\n";

    // Capture all local variables by reference:
    [&]() { std::cout << x << ", " << y << ", " << z << ".\n\n"; }();

    return 0;
}
