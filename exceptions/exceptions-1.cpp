#include <iostream>
#include <exception>

int main () {
	try {
		// Вряд ли у нас найдётся столько памяти
		int* myarray= new int[1000000000000000000ULL];
	}
	catch (std::exception& e) {
		std::cout << "Standard exception: " << e.what() << std::endl;
	}
	return 0;
}
