#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::string	filename = "test.dat";

	// Can also use std::ifstream without the need for 
	// specifying std::ios::in.
	std::fstream inputFile;
	inputFile.open(filename, std::ios::in);

	if (inputFile.is_open()) {
		std::string line {};

		// Read until the end of file.
		// This can be done also by doing:
		// while (inputFile) { ... } because the bool operator
		// inside the fstream class is overloaded.
		while (!inputFile.eof()) {
			getline(inputFile, line);
			std::cout << line << std::endl;
		}

		inputFile.close();
	}
	else {
		std::cout << "Cannot open file: " << filename << std::endl;
	}
}

