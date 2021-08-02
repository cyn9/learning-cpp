#include <iostream>
#include <fstream>
#include <vector>

int main() {
	std::size_t N {0};
	auto V = std::vector<int>();
	
	std::cout << "Enter number of lines to be written: ";
	std::cin >> N;

	V.reserve(N);

	for (std::size_t i = 0; i < N; ++i)
		V.emplace_back(i+1);

	std::string filename = "output.dat";
	std::fstream outFile;
	outFile.open(filename, std::ios::out);

	if (outFile.is_open()) {
		int count {1};
		for (const auto e: V) {
			outFile << "#" << count << ": " << e << std::endl;
			count++;
		}

		std::cout << "Writing complete.\n";
		outFile.close();
	}
	else {
		std::cout << "Cannot create file:" << filename << std::endl;
	}
	
	return 0;
}

