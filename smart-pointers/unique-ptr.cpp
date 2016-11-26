#include <iostream>
#include <memory>
#include <cassert>

/// std::unique_ptr -- "умный указатель",
/// обеспечивающий единоличное владение ресурсом.
/// std::make_unique требует C++14

struct A {
	~A() { std::cout << "A::~A()" << std::endl; }
};

int main() {
	std::unique_ptr<A> a = std::make_unique<A>();
	std::cout << "(bool)a == " << (bool)a << std::endl;
	
	/// Копирование и присваивание запрещено при компиляции
	// std::unique_ptr<A> b = a;
	
	/// Разрешено только перемещение
	std::unique_ptr<A> b = std::move(a);
	std::cout << "(bool)b == " << (bool)b << std::endl;
	std::cout << "(bool)a == " << (bool)a << std::endl;
	
	return 0;
}
