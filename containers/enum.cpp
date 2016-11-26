#include <iostream>
#include <map>

enum class Quantity {
	LENGTH,
	TIME,
	MASS,
	PRESSURE
};


int main() {
	std::map<Quantity, std::string> quantities = {
		{Quantity::LENGTH,      "m"},
		{Quantity::TIME,        "s"},
		{Quantity::MASS,        "kg"},
		{Quantity::PRESSURE,    "Pa"},
	};
	
	for (auto q : quantities) {
		std::cout << (int)(q.first) << ":\t" << q.second << std::endl;
	}
	return 0;
}
