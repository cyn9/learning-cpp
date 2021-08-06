#include <iostream>
#include <vector>
#include <algorithm>

bool check(const std::string &text) {
    constexpr int test_size {3};

    return text.size() == test_size;
}

struct Check {
    static constexpr int test_size {3};

    bool operator()(const std::string &text) {
        return text.size() == test_size;
    }
} check_size;

// Here, func_name is a function that expects a std::string reference
// and returns a bool. func_name function implements size comparison
// of the local temp variable with the test_size variable.
void run(std::function<bool (std::string &)> func_name) {
    std::string temp {"ten"};
    
    std::cout << func_name(temp) << '\n';
}

int main() {
    std::cout << std::boolalpha;

    std::vector<std::string> V {"one", "two", "three", "ten"};

    constexpr int test_size {3};

    // Passing a lambda to count_if function:
    int count = std::count_if(V.begin(), V.end(), [&](std::string str) -> bool {
        return str.size() == test_size;
    });

    std::cout << count << '\n';

    // Passing a function pointer (defined as check()) to count_if function:
    count = std::count_if(V.begin(), V.end(), check);
    std::cout << count << '\n';

    // Passing a functor (defined as Check) to count_if function:
    count = std::count_if(V.begin(), V.end(), check_size);
    std::cout << count << '\n';

    // Demo: Functional types
    auto foo = [&](std::string str) -> bool {
        return str.size() == test_size;
    };

    // Passing a lambda to a functional type:
    run(foo);

    // Passing a functor to a functional type:
    run(check_size);

    // Passing a function pointer to a functional type:
    run(check);

    // Functional with a return type of int, and expected arguments are both int.
    std::function<int(int, int)> add = [](int x, int y) -> int { return x + y; };
    std::cout << add(5, 2) << '\n';

    return 0;
}
