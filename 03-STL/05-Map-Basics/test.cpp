#include <iostream>
#include <map>
#include <utility>
#include <string>

void printMap(const std::map<std::string, int> &);
void iterateMap(const std::map<std::string, int> &);

int main() {
    std::map<std::string, int> people;

    // Insert key-value pair:
    people["John"] = 23;
    people["Jane"] = 21;
    people["Judy"] = 35;
    printMap(people);

    // Find function returns an iterator.
    if (people.find("Sue") != people.end())
        std::cout << "Found \"Sue\" in the map.\n";
    else
        std::cout << "Could not find \"Sue\" in the map.\n";

    iterateMap(people);

    // Insert an element to the map using std::pair
    // Note: Keys are stored in an alphabetical order.
    std::pair<std::string, int> person("Becky", 43);
    people.insert(person);

    // Also make_pair can be used to get the correct types:
    people.insert(std::make_pair("Ted", 48));

    std::cout << '\n';
    iterateMap(people);

    return 0;
}

void printMap(const std::map<std::string, int> &p) {
    std::map<std::string, int>::const_iterator it = p.begin();

    while (it != p.end()) {
        std::cout << it->first << ": " << it->second << '\n';

        it++;
    }

    std::cout << '\n';
}

// Another way to iterate through the map is to use std::pair
void iterateMap(const std::map<std::string, int> &p) {
    std::map<std::string, int>::const_iterator it = p.begin();

    while (it != p.end()) {
        std::pair<std::string, int> person = *it;

        std::cout << person.first << ": " << person.second << '\n';

        it++;
    }
}
