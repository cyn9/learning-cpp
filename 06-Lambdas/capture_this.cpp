#include <iostream>

class Test {
    private:
        int a {1};
        int b {2};
    
    public:
        Test() = default;

        void print() {
            int x {3};
            int y {4};

            // To be able to use private members of the class (which are actually of 
            // class instances), "this" needs to be captured by the lambda.
            // Example lambda here: pass all local variables as reference, and pass 
            // "this" as well.
            auto foo = [&, this]() {
                // "this" is passed to the lambda by reference (default).
                // this->a = 100;
                // this->b = 200;

                std::cout << x << ", " << y << ", " << a << ", " << b << std::endl;
            };

            foo();
        }

        void setNumbers(int a, int b) {
            this->a = a; 
            this->b = b;
        }
};

int main() {
    Test t;
    t.print();

    t.setNumbers(40, 50);
    t.print();

    return 0;
}
