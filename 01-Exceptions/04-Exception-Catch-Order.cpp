#include <iostream>
#include <exception>

void foo() {
	bool error1 = true;
	bool error2 = false;

	if (error1) {
		throw std::bad_alloc();
	}

	if (error2) {
		throw std::exception();
	}
}

int main() {
	try {
		foo();
	}
	// Catch order is important. The order should be: first throw
	// subclasses (classes that inherits from std::exception). Then
	// throw exceptions from base classes. Otherwise there is a
	// order problem due to the polymorphic relation between the base
	// and the derived classes.
	catch(const std::bad_alloc &e) {
		std::cout << "Catching bad alloc: " << e.what() << '\n';
	}
	catch(const std::exception &e) {
		std::cout << "Catching exception: " << e.what() << '\n';
	}
}
