// Demonstration for reading and writing binary files.

#include <iostream>
#include <fstream>
#include <string>

// Align this data with byte boundaries.
// Surround the struct with this pragma directive.
// Make sure the struct is not padded.
#pragma pack(push, 1)
struct Person {
    char name[50];
    int age;
    double weight;
};
#pragma pack(pop)

int main() {
    std::cout << "sizeof(char[50]) is " << 50*sizeof(char) << ".\n";
    std::cout << "sizeof(int) is " << sizeof(int) << ".\n";
    std::cout << "sizeof(double) is " << sizeof(double) << ".\n";
    std::cout << "Total size is " << 50*sizeof(char) + 
                                        sizeof(int) + 
                                        sizeof(double) << ".\n";

    std::cout << "sizeof(Person) is " << sizeof(Person) << ".\n";

    // Note: C++ uses struct padding for more efficient way of 
    // representing and storing the struct data in the memory.
    // To write the struct data to a file, we should disable this
    // padding property using a pragma directive.

    // Writing binary file:

    // Why not initalize the struct with a C++20 style of "designated
    // initalizers".
    Person p1 = {.name = "John Doe", 
                 .age = 32, 
                 .weight = 170};

    std::string filename = "test.bin";
    
    std::fstream outFile;
    outFile.open(filename, std::ios::binary | std::ios::out);

    if (outFile.is_open()) {
        outFile.write(reinterpret_cast<char *>(&p1), sizeof(Person));
        outFile.close();
    }
    else {
        std::cout << "Cannot create " << filename << std::endl;
    }

    // Reading binary file:
    Person pRead = {}; // New data to be read from binary file.

    std::fstream inFile;
    inFile.open(filename, std::ios::binary | std::ios::in);

    if (inFile.is_open()) {
        inFile.read(reinterpret_cast<char *>(&pRead), sizeof(Person));
        inFile.close();
    }
    else {
        std::cout << "Cannot open " << filename << std::endl;
    }

    std::cout << '\n';
    std::cout << "Name: " << pRead.name << ", "
              << "Age: " << pRead.age << ", "
              << "Weight: " << pRead.weight << "lbs." << std::endl;

    return 0;
}
