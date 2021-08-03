#include <iostream>
#include <vector>

int main() {
    std::vector<double> V;
    V.reserve(6000);

    int capacity = V.capacity();
    std::cout << "Capacity: " << capacity << '\n';

    for (auto i = 0; i < 10000; ++i) {
        if (V.capacity() > capacity) {
            capacity = V.capacity();
            std::cout << "Capacity: " << capacity << '\n';
        }

        V.push_back(i);
    }

    // Discard elements using resize()
    V.resize(100);
    std::cout << "Size: " << V.size() << '\n';
    std::cout << "Capacity: " << V.capacity() << '\n';

    // Find out sizeof a vector
    std::vector<int> X;
    X.reserve(100);

    std::cout << "Size: " << X.size() << '\n';
    std::cout << "Capacity: " << X.capacity() << '\n';
    std::cout << "sizeof(X): " << sizeof(X) << '\n';

    // 24 bytes = 3 pointers * 8 bytes
    // https://stackoverflow.com/questions/34024805/c-sizeof-vector-is-24 

    return 0;
}
