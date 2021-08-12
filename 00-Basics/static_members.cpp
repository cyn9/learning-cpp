#include <iostream>

class Foo {
    private:
        // Suppress warnings if these variables are not used.
        [[maybe_unused]] int x;
        [[maybe_unused]] double y;
        
        static int count;
    
    public:
        Foo()                : Foo(0, 0.0) {}
        Foo(int x, double y) : x{x}, y{y}  { Foo::count++; }
        ~Foo() { Foo::count--; }

        static int getCount() { return Foo::count; }
};

int Foo::count {0};

int main() {
    Foo f1;
    std::cout << "Number of Foo objects: " << Foo::getCount() << '\n';
    // No-arg constructor calls delegate constructor Foo(int, double), hence,
    // a total of two constructor calls are being made. That's why no-args
    // constructor does not have count increment.

    Foo f2(3, 4.2);
    std::cout << "Number of Foo objects: " << Foo::getCount() << '\n';
    
    return 0;
}
