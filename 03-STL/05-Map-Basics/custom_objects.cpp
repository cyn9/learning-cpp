#include <iostream>
#include <map>
#include <string>

class Person;
void print(const std::map<int, Person> &);

class Person {
    private:
        std::string name;
        int age;

    public:
        Person()                          : Person("", 0) {
            std::cout << "No-args constructor called.\n";
        }

        Person(std::string name, int age) : name{name}, age{age} {
            std::cout << "Two-args constructor called.\n";
        }

        // C++ default copy constructor only provides a shallow copying.
        // Copy constructor:
        Person(const Person &rhs) {
            std::cout << "Copy constructor called.\n";
            this->name = rhs.name;
            this->age = rhs.age;
        }

        ~Person() {}

        void print() const {
            std::cout << name << ", " << age << std::endl;
        }
};

int main() {
    std::map<int, Person> people;

    // Observe the ascending sort of key values.
    people[2] = Person("Mike", 33);
    people[3] = Person("John", 27);
    people[1] = Person("Taj", 44);
    people[0] = Person("Mel", 65);

    print(people);

    people.insert(std::make_pair(4, Person("Zac", 30)));
    print(people);

    return 0;
}

void print(const std::map<int, Person> &people) {
    for (auto it = people.begin(); it != people.end(); ++it) {
        std::cout << it->first << " >> ";
        it->second.print();
    }
}
