#include <iostream>

int main() {
	try {
//		throw 1;
//		throw 'c';
		throw 0.1;
	} catch (int exception) {
		std::cout << exception << std::endl;
	} catch (char exception) {
		std::cout << exception << std::endl;
	} catch (...) {
		std::cout << "Unknown exception" << std::endl;
	}
	return 0;
}

