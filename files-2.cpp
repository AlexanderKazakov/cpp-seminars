#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
	std::ifstream input("testBin.txt", std::ios::binary);
	/// Скопировать данные в вектор байтов
	std::vector<char> buffer(
			(std::istreambuf_iterator<char>(input)),
			(std::istreambuf_iterator<char>()));
	std::cout << buffer.size() << std::endl;
	return 0;
}

