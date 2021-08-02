#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::string filename = "stats.dat";

	std::fstream file;

	file.open(filename, std::ios::in);

	if (file.is_open()) {
		while(!file.eof()) {
			std::string line {};
			int population;

			std::getline(file, line, ':');
			file >> population;
			// file.get(); // Helps discard the newline character at the end of the line.
			// More robust solution than file.get() is:
			file >> std::ws;
			
			// If end of the file is reached, terminate the loop.
			if (!file)	break;

			std::cout << line << " has a population of " << population << '\n';
		}

		file.close();
	}
	else {
		std::cout << "Cannot open file: " << filename << std::endl;
	}
}
