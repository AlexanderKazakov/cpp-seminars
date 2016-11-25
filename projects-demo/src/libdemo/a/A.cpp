#include <iostream>

#include "libdemo/a/A.hpp"

/// Если файл можно не подключать в ".hpp" (достаточно в ".cpp"),
/// то так и стоит поступать. Это позволяет избежать циклических
/// зависимостей и ненужных пересборок
#include "libdemo/c/c.hpp"


using namespace demo;

void A::print() const {
	std::cout << "A::print()" << std::endl;
	foo();
}
