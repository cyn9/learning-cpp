#include <iostream>
#include <string>

void foo(void);

void usesFoo() {
	// Still can catch the error even if the error-prone
	// function is called by another function.
	foo();
}

// Assume that something can go wrong with this function.
void foo() {
	bool err1 = false;
	bool err2 = true;
	
	// As soon as the first exception is thrown, the foo()
	// function goes out of scope.
	if (err1)
		throw "Something went wrong.";

	// This error creates a new string object and passes it
	// to the catch block. Better to pass by reference.
	if (err2)
		throw std::string("Something else went wrong.");
}

int main() {
	try {
		usesFoo();
	}
	catch (int e) {
		std::cout << "Error code: " << e << '\n';
	}
	catch (const char *e) {
		std::cout << "Error message: " << e << '\n';
	}
	catch (std::string &e) {
		std::cout << "String error message: " << e << '\n';
	}
	
	std::cout << "Program continued after throwing error.\n";

	return 0;
}
