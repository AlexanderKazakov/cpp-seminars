#include <iostream>

#if __cplusplus >= 201103L
#define THROWING_DESTRUCTOR_SPECIFICATION noexcept(false)
#else
#define THROWING_DESTRUCTOR_SPECIFICATION
#endif


class Bad {
public:
	~Bad() THROWING_DESTRUCTOR_SPECIFICATION {
		std::cout << "In Bad's destructor" << std::endl;
		throw 'a';
	}
};


int main() {
	try {
		Bad   bad;
		// По завершении блока будет вызван деструктор объекта bad,
		// который бросит исключение. В данном случае оно будет поймано
		
	} catch(...) {
		std::cout << "Will be printed" << std::endl;
	}
	
	try {
		Bad   bad;
		throw 2;
		// При раскрутке стека будет вызван деструктор объекта bad.
		// Деструктор бросит исключение. Обработка более чем одного исключения 
		// одновременна запрещена, поэтому программа аварийно завершится
		
	} catch(...) {
		std::cout << "Will not be printed" << std::endl;
	}
	
	
	// Может быть, это сработает?
	try {
		try {
			Bad   bad;
			throw 2;
			
		} catch(...) {
			std::cout << "Will not be printed" << std::endl;
		}
	} catch (...) {
		std::cout << "Will it be printed?" << std::endl;
	}
}
