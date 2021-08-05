#include <iostream>

struct Base {
    virtual bool operator()(const std::string &text) const = 0;

    virtual ~Base() {}
};

struct Match : public Base {
    virtual bool operator()(const std::string &text) const {
        return text == "Hello";
    }
};

void check(const std::string &str, const Base &base) {
    if (base(str))
        std::cout << "Text matches...\n";
    else
        std::cout << "Text does not match...\n";
}

int main() {
    std::cout << std::boolalpha;

    Match m;
    check("Hello", m);
    check("Hi!", m);

    return 0;
}
