#include <iostream>
#include <set>
#include <string>

class Test {
    private:
        std::string name;
        int id;

    public:
        Test() : Test("", -1) {}
        Test(std::string name, int id) : name{name}, id{id} {}

        Test(const Test &rhs) {
            this->name = rhs.name;
            this->id = rhs.id;
        }

        ~Test() {}

        void print() const {
            std::cout << id << ": " << name << std::endl;
        }

        bool operator<(const Test &rhs) const {
            return this->name < rhs.name;
        }
};

int main() {
    std::set<int> numbers;

    numbers.insert(50);
    numbers.insert(20);
    numbers.insert(10);
    numbers.insert(60);
    numbers.insert(60);
    numbers.insert(20);

    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << "\n\n";

    std::set<Test> test_set;

    // emplace: constructs element in-place
    test_set.emplace("Test A", 100);
    test_set.emplace("Test B", 106);
    test_set.emplace("Test C", 102);
    test_set.emplace("Test D", 103);

    for (auto it = test_set.begin(); it != test_set.end(); ++it) {
        it->print();
    }

    return 0;
}
