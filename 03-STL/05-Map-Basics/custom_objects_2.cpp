#include <iostream>
#include <map>
#include <string>

class Person;
void print(const std::map<Person, int> &);

class Person {
    private:
        std::string name;
        int age;

    public:
        Person()                          : Person("", 0)        {}
        Person(std::string name, int age) : name{name}, age{age} {}

        // C++ default copy constructor only provides a shallow copying.
        // Copy constructor:
        Person(const Person &rhs) {
            this->name = rhs.name;
            this->age = rhs.age;
        }

        ~Person() {}

        // Overload comparison operator to make a suitable ordering for
        // key values in the map that are of string variable in Person
        // class. Although the names are the same, since the ages are
        // different, then the keys are also different.
        bool operator<(const Person &rhs) const {
            if (this->name == rhs.name)     return this->age < rhs.age;
            else                            return this->name < rhs.name;
        }

        void print() const {
            std::cout << name << ", " << age << std::endl;
        }
};

int main() {
    std::map<Person, int> people;

    people[Person("Alfred", 23)] = 23;
    people[Person("Cindy", 45)] = 45;
    people[Person("Becky", 37)] = 37;
    people[Person("Cindy", 35)] = 35;

    print(people);

    return 0;
}

void print(const std::map<Person, int> &people) {
    for (auto it = people.begin(); it != people.end(); ++it) {
        std::cout << it->second << " >> ";
        it->first.print();
    }
}
