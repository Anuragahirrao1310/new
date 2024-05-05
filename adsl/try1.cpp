#include <iostream>
 #include <fstream>

int main() {
std::ofstream outFile; outFile.open("example.txt"); if (!outFile.is_open()) {
std::cerr << "Error opening the file!" << std::endl; return 1;
}
outFile << "Hello world, this is some text written to the file." << std::endl; outFile.close();

std::ifstream inFile; inFile.open("example.txt"); if (!inFile.is_open()) {
std::cerr << "Error opening the file!" << std::endl; return 1;
}
std::string line;
while (std::getline(inFile, line)) { std::cout << line << std::endl;
}
inFile.close();

return 0;
}
