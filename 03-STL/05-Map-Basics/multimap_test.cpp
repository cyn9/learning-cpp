#include <iostream>
#include <map>
#include <string>
#include <utility>

int main() {
    std::multimap<int, std::string> mm;

    mm.insert(std::make_pair(30, "Mike"));
    mm.insert(std::make_pair(10, "John"));
    mm.insert(std::make_pair(30, "Nick"));
    mm.insert(std::make_pair(20, "Sarah"));
    mm.insert(std::make_pair(40, "Raj"));
    mm.insert(std::make_pair(50, "Rick"));
    mm.insert(std::make_pair(60, "Cam"));

    for (auto it = mm.begin(); it != mm.end(); ++it)
        std::cout << it->first << " >> " << it->second << std::endl;

    std::cout << '\n';

    std::pair<std::multimap<int, std::string>::iterator, 
              std::multimap<int, std::string>::iterator> range = mm.equal_range(30);

    for (auto it = range.first; it != range.second; ++it)
        std::cout << it->first << " >> " << it->second << std::endl;

    return 0;
}
