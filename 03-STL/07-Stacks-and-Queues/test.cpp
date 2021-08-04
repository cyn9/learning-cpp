#include <iostream>
#include <string>
#include <stack>
#include <queue>

class Test {
    private:
        std::string s;
    
    public:
        Test() : Test("") {}
        Test(std::string s) : s{s} {}

        Test(const Test &rhs) {
            this->s = rhs.s;
        }

        Test(Test &&rhs) {
            this->s = rhs.s;
        }

        ~Test() {}

        void print() const {
            std::cout << this->s << std::endl;
        }
};

int main() {
    // Stack example:
    // Stack = LIFO.
    std::stack<Test> test;
    test.push(Test("Ace"));
    test.push(Test("Joker"));
    test.push(Test("Seven"));

    // Stacks are not itarable.
    // .top() returns reference to the top element in the stack
    Test &t1 = test.top();
    t1.print();

    test.pop();
    Test &t2 = test.top();
    t2.print();

    std::cout << std::endl;

    // Note: Once the topmost element is popped from the stack,
    //       the reference variable to that element is invalidated.

    // Stack iteration with pop() example:
    std::stack<Test> stack_test;
    stack_test.emplace("John");
    stack_test.emplace("Mary");
    stack_test.emplace("Hailie");
    stack_test.emplace("Kate");

    while (!stack_test.empty()) {
        Test &temp = stack_test.top();
        temp.print();

        stack_test.pop();
    }

    std::cout << std::endl;

    // Queue example:
    // Queue = FIFO.
    std::queue<Test> queue_test;
    queue_test.emplace("Wilma");
    queue_test.emplace("Scooby");
    queue_test.emplace("Shaggy");
    queue_test.emplace("Daphne");

    while (!queue_test.empty()) {
        Test &temp = queue_test.front();
        temp.print();

        queue_test.pop();
    }

    return 0;
}
