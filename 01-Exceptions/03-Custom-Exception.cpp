#include <iostream>
#include <exception>

class MyException: public std::exception {
	public:
		virtual const char* what() const noexcept {
			return "Error...";		
		}
};

class Test {
	public:
		void foo() {
			throw MyException{};
		}
};
int main() {
	Test t;

	try {
		t.foo();
	}
	catch(const MyException &e) {
		std::cout << e.what() << '\n';
	}
}

