#include <iostream>

class Foo {
	public:
		Foo() {
			char *pMem = new char[999999999999999];
			delete[] pMem;
		}
};

int main() {
	try {
		Foo();
	}
	catch (std::bad_alloc &e) {
		std::cout << "Caught an exception: \n";
		std::cout << e.what() << '\n';
	}
	
	std::cout << "Program continued to run.\n";

	return 0;
}
