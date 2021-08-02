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
		Foo foo;
	}
	// Catch argument with const reference if it is 
	// an object.
	catch (const std::bad_alloc &e) {
		std::cout << "\n\nCaught an exception: \n";
		std::cout << e.what() << '\n';
	}
	
	std::cout << "Program continued to run.\n";

	return 0;
}
