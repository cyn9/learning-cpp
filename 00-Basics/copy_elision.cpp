#include <iostream>
#include <vector>

// Wikipedia: https://en.wikipedia.org/wiki/Copy_elision
// Copy elision refers a compiler optimization technique 
// that eliminates unnecessary copying of objects.
// As defined by cppreference.com, copy elision omits
// copy and move constructors, resulting in zero-copy
// pass-by-value semantics.

class Foo {
    public:
        Foo() { std::cout << "No-args constructor.\n"; }
        Foo(int i) { std::cout << "Single-arg constructor.\n"; }
        Foo(const Foo& src) { std::cout << "Copy constructor.\n"; }
        ~Foo() { std::cout << "Destructor.\n"; }

        Foo &operator=(const Foo& src) { 
            std::cout << "Overloaded assignment operator."; 
            return *this;
        }

        friend std::ostream &operator<<(std::ostream &out, const Foo &foo);
};

std::ostream &operator<<(std::ostream &out, const Foo &foo) {
    out << "Hello from Foo object.\n";
    return out;
}

Foo getFoo() { 
    return Foo(); 
}

int main() {
    // With function:
    Foo foo1 = getFoo();
    std::cout << foo1 << '\n';

    // With lambda:
    auto getNewFoo = []() -> Foo { return Foo(); };
    Foo foo2 = getNewFoo();
    std::cout << foo2 << '\n';

    // Test with a vector:
    std::vector<Foo> V;
    V.push_back(Foo());

    return 0;
}