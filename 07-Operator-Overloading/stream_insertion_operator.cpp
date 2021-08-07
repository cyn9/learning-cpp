#include <iostream>
#include <string>

class Foo {
    private:
        int id;
        std::string name;
    
    public:
        Foo() : Foo(0, "") {}
        Foo(int id, std::string name) : id {id}, name {name} {}

        Foo(const Foo& rhs) {
            std::cout << "Copy constructor called.\n";
            this->id = rhs.id;
            this->name = rhs.name;
        }

        ~Foo() {}

        void print() const {
            std::cout << id << ": " << name << '\n';
        }

        // Overloading assignment operator:
        const Foo &operator=(const Foo &source) {
            std::cout << "Assignment operator overloaded.\n";
            this->id = source.id;
            this->name = source.name;

             return *this;
        }

        // Overloading stream extraction operator:
        friend std::ostream &operator<<(std::ostream &out, const Foo &source);
};

std::ostream &operator<<(std::ostream &out, const Foo &obj) {
    out << obj.id << ": " << obj.name;

    return out;
}

int main() {
    // Single stream extraction operator:
    Foo f {99, "John Doe"};
    std::cout << f << '\n';

    // Multiple stream extraction operators:
    Foo foo1 {1, "Jane"};
    Foo foo2 {2, "Jasper"};
    std::cout << foo1 << ", " << foo2 << '\n';

    return 0;
}
