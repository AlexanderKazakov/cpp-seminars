#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>


void textMode(const std::string& fileNameIn, const std::string& fileNameOut) {
	/// Открыть файл для чтения
	std::ifstream input(fileNameIn);
	assert(input.is_open());
	
	/// Считать как текстовый файл, преобразуя к int'ам
	std::vector<int> data;
	int i;
	while (input >> i) {
		data.push_back(i);
		std::cout << "Read integer: " << i << std::endl;
	}
	
	/// Закрыть файл (input.good() == false, т.к. достигли конца файла)
	assert(!input.bad());
	input.close();
	
	/// Открыть файл для записи
	std::ofstream output;
	output.open(fileNameOut, std::ios::out); // или std::ios::app -- дозаписать в конец
	assert(output.is_open());
	
	/// Записать информацию
	for (int i : data) { output << i << " "; }
	
	/// Закрыть файл
	assert(output.good());
	output.close();
}

void textModeGetline(const std::string& fileNameIn) {
	/// Открыть файл для чтения
	std::ifstream input(fileNameIn);
	assert(input.is_open());
	
	/// Считать одну строку
	std::string s;
	std::getline(input, s);
	std::cout << "Read string \"" << s << "\"" << std::endl;
	
	/// Закрыть файл (input.good() == false, т.к. достигли конца файла)
	assert(!input.bad());
	input.close();
}

void binaryMode(const std::string& fileName) {
	std::ofstream output;
	output.open(fileName, std::ios::binary);
	assert(output.is_open());
	
	std::vector<double> data = { 1, 2, 3 };
	
	std::streamsize bufferSize = (std::streamsize)(data.size() * sizeof(double));
	std::streamsize previousNumberOfBytes = output.tellp();
	
	/// Записать как массив байт
	assert(output.write(reinterpret_cast<const char*>(data.data()), bufferSize));
	
	std::streamsize currentNumberOfBytes = output.tellp();
	assert(bufferSize == currentNumberOfBytes - previousNumberOfBytes);
	
	assert(output.good());
	output.close();
}

int main() {
	const std::string fileNameIn  = "testIn.txt";
	const std::string fileNameOut = "testOut.txt";
	const std::string binFileName = "testBin.txt";
	
	textMode(fileNameIn, fileNameOut);
	textModeGetline(fileNameIn);
	binaryMode(binFileName);
	
	return 0;
}

