#include <iostream>
#include <string>
#include <vector>

// Return true if the string has three letters.
bool match(const std::string &str) {
    return str.size() == 3;
}

// Pass the function pointer as an argument to the function
int countStrings(const std::vector<std::string> &str, bool (*match)(const std::string &str)) {
    int count {0};

    for (const auto &e: str) {
        if (match(e)) 
            count++;
    }

    return count;
}

int main() {
    std::vector<std::string> V;
    V.reserve(6);

    V.push_back("one");
    V.push_back("two");
    V.push_back("three");
    V.push_back("four");
    V.push_back("two");
    V.push_back("one");

    std::cout << countStrings(V, match) << std::endl;

    return 0;
}
