#include <iostream>
#include <exception>

// Своя иерархия исключений

struct E : public std::exception { 
	virtual const char* what() const noexcept override {
		return "E\n";} };
struct E1 : E {
	virtual const char* what() const noexcept  override {
		return "E1\n";} };
struct E2 : E { 
	virtual const char* what() const noexcept override {
		return"E2\n";} };

int main() {
	try {
		try {
			throw E1();
		} catch (E& e) {
			std::cout << e.what() << std::endl;
			throw E2();
		}
	} catch (E& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}

