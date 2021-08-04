#include <iostream>
#include <vector>
#include <map>
#include <string>

int main() {
    std::map<std::string, std::vector<int>> grades;

    grades["Becky"].push_back(75);
    grades["Becky"].push_back(90);
    grades["Tom"].push_back(95);
    grades["Tom"].push_back(80);

    for (auto &e: grades) {
        std::cout << e.first << " \t : "; 

        for (auto &v: e.second) {
            std::cout << v << " ";
        }
        
        std::cout << std::endl;
    }

    return 0;
}
