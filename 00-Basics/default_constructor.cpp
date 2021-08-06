#include <iostream>
#include <string>

class Test {
    private:
        int m_id {3};
        std::string m_name {"John Doe"};

    public:
        // Explicitly defaulted no-arg and copy constructors:
        // Another constructor exists (Test(int) in this case)
        // therefore Test::Test() is needed to be declared
        // explicitly.
        Test() = default;
        Test(const Test& src) = default;
        Test &operator=(const Test& src) = default;

        Test(int id) : m_id {id} {}

        void print() const {
            std::cout << m_id << ": " << m_name << std::endl;
        }
};

int main() {
    Test t1;
    t1.print();

    Test t2(333);
    t2.print();

    Test t3 = t2;
    t3.print();

    return 0;
}