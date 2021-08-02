#include <iostream>
#include <fstream>

int main() {
	std::fstream outFile;
	std::string filename = "text2.txt";

	outFile.open(filename, std::ios::out);

	if (outFile.is_open()) {
		outFile << "Fstream test. Hello, C++." << std::endl;
		outFile << 987 << std::endl;

		outFile.close();
	}
	else {
		std::cout << "Cannot create file: " << filename << '\n'; 
	}

	return 0;
}
