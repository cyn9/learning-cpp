#include <iostream>
#include <typeinfo>

// Possible to use decltype with expressions.
template <typename T, typename S>
auto foo(T t, S s) -> decltype(t + s) { return t + s; }

// Possible to use decltype with functions.
int test() { return 9999; }

auto test_func() -> decltype(test()) { return test(); }

int main() {
    std::cout << "Type of test() is " << typeid(test()).name() << std::endl;
    std::cout << "Type of test_func() is " << typeid(test_func()).name() << std::endl;

    std::cout << foo(5, 6.2f) << std::endl;
    std::cout << test_func() << std::endl;

    return 0;
}
