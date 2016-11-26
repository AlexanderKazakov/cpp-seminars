#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <cassert>

/// Класс, целиком состоящий из static функций, может быть использован 
/// просто как пространство имён
class StringUtils {
public:
	/**
	 * Print number to string of specified length with leading zeroes
	 */
	static std::string toString(const int number, const int length) {
		std::ostringstream strStream;
		strStream << std::setfill('0') << std::setw(length) << number;
		return strStream.str();
	}
	
	/**
	 * Split the string into vector of strings by given delimiter symbol.
	 * Several repeating delimiters handled as one.
	 */
	static std::vector<std::string> split(const std::string s, const char delim) {
		std::vector<std::string> ans;
		std::stringstream ss(s);
		std::string item;
		while (std::getline(ss, item, delim)) {
			if (item != "") { //< prevent empty strings if delimiter is repeating
				ans.push_back(item);
			}
		}
		return ans;
	}
};


int main(int argc, char* argv[]) {
	/// Для более удобной обработки аргументов командной строки 
	/// см. функции getopt, getopt_long, getopt_long_only
	assert(argc == 2);
	double input = std::atof(argv[1]);
	std::cout << "input == " << input << std::endl;
	
	std::string s = std::to_string(input);
	std::cout << "s == " << s << std::endl;
	s += s;
	std::cout << "after \"s += s\" s == " << s << std::endl;
	std::cout << "s.size() == " << s.size() << std::endl;
	std::cout << "s.find(0) == " << s.find("0") << std::endl;
	
	auto items = StringUtils::split(s, '0');
	for (auto item : items) { std::cout << item << std::endl; }
	
	std::cout << StringUtils::toString(55, 4);
	
	return 0;
}
