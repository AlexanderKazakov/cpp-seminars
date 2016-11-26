#include <iostream>


class Bad {
public:
	~Bad() {
		std::cout << "In Bad's destructor" << std::endl;
	}
};


int main() {
	try {
		Bad bad;
	} catch(...) {
		std::cout << "In exception handling block 1" << std::endl;
	}
	
	try {
		Bad   bad;
		throw 2;
	} catch(...) {
		std::cout << "In exception handling block 2" << std::endl;
	}
}
