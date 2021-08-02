#include <iostream>
#include <fstream>

int main() {
	std::ofstream outFile;
	std::string filename = "text.txt";

	outFile.open(filename);

	if (outFile.is_open()) {
		outFile << "Hello, C++." << std::endl;
		outFile << 13579 << std::endl;

		outFile.close();
	}
	else {
		std::cout << "Could not create file: " << filename << '\n';
	}

	return 0;
}

