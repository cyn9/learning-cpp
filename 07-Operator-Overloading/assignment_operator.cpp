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

        // Setters:
        void setID(int id)             { this->id = id; }
        void setName(std::string name) { this->name = name; }
};

int main() {
    Foo foo1 {1, "John Doe"};
    foo1.print();

    Foo foo2 = foo1; // Calls copy constructor as it is copy initialization.
    foo2.print();

    Foo foo3;
    foo3 = foo2; // Assignment operator overloaded.

    foo3.setName("Jane Doe");
    foo3.setID(99);

    Foo foo4;
    foo4.operator=(foo3); // Same thing with foo4 = foo3.
    foo4.print();

    return 0;
}
