#include <iostream>
#include <string>
#include <vector>

class Test;
void printVector(const std::vector<Test> &);

class Test {
    private:
        std::string m_name;
        int m_id;
    
    public:
        Test() : Test("", -1) {}
        Test(std::string name, int id) : m_name {name}, m_id{id} {}

        ~Test() {}

        Test(const Test &rhs) {
            this->m_name = rhs.m_name;
            this->m_id = rhs.m_id;
        }

        bool operator<(const Test &rhs) const {
            if (this->m_id == rhs.m_id) {
                return this->m_name < rhs.m_name;
            }
            else {
                return this->m_id < rhs.m_id;
            }
        }

        void print() const {
            std::cout << "ID: " << m_id << ", Name: " << m_name << std::endl;
        }
};

int main() {
    auto test = std::vector<Test>();
    test.emplace_back("Dana", 5);
    test.emplace_back("Rick", 45);
    test.emplace_back("Seth", 33);
    test.emplace_back("Becky", 33);
    test.emplace_back("Ruth", 27);

    printVector(test);

    std::sort(test.begin(), test.end());
    printVector(test);

    return 0;
}

void printVector(const std::vector<Test> &V) {
    for (const auto &e: V)
        e.print();

    std::cout << std::endl;
}
