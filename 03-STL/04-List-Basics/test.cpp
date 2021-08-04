#include <iostream>
#include <list>

void printList(const std::list<int> &);

int main() {
    std::list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    printList(numbers);

    numbers.push_front(4);
    printList(numbers);

    auto it = numbers.begin();
    it++;
    numbers.insert(it, 100);
    printList(numbers);

    it = numbers.begin();
    it++;
    it = numbers.erase(it);
    printList(numbers);

    return 0;
}

void printList(const std::list<int> &numbers) {
    // auto is actually "std::list<int>::iterator"
    for (auto it = numbers.begin(); it != numbers.end(); ++it)
        std::cout << *it << "  ";

    std::cout << '\n';
}
