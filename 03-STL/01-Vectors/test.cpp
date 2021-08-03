#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> V;

    V.push_back("one");
    V.push_back("two");
    V.push_back("three");
    V.push_back("four");

    // Create and iterator to iterate over V:
    std::vector<std::string>::iterator it = V.begin();

    std::cout << "The first element: " << *it << '\n';

    // Loop through an iterator:
    for (auto it = V.begin(); it != V.end(); ++it)
        std::cout << *it << '\n';

    return 0;
}
