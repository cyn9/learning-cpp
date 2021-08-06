#include <iostream>
#include <vector>

template <typename T>
class Test {
    private:
        std::vector<T> m_container;
    
    public:
        Test<T>(const std::initializer_list<T> &list) {
            for (const auto &e: list) {
                std::cout << e << " is added.\n";

                m_container.push_back(e);
            }
        }

        void print() const {
            std::cout << "Container content: ";

            for (const auto &e: m_container)
                std::cout << e << " ";
            
            std::cout << '\n';
        }
};

int main() {
    Test<int> test1 {1, 2, 3, 5, 6, 7};
    test1.print();
    std::cout << '\n';

    Test<std::string> test2 {"apple", "kiwi", "orange"};
    test2.print();
    std::cout << '\n';

    return 0;
}