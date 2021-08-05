#include <iostream>
#include <string>

inline void foo(const std::string &str) {
    std::cout << "Hello, " << str << std::endl;
}

int main() {
    void (*fooPtr)(const std::string &) = &foo;

    fooPtr("C++.");

    return 0;
}
