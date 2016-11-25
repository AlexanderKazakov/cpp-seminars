#ifndef LIBGCM_STRINGUTILS_HPP
#define LIBGCM_STRINGUTILS_HPP

#include <iomanip>
#include <sstream>
#include <vector>

namespace gcm {

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


}

#endif /* LIBGCM_STRINGUTILS_HPP */
