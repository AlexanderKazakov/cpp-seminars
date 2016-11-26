#include <iostream>
#include <memory>

/// Forward declaration
struct B;

struct A {
	~A() { std::cout << "A::~A()" << std::endl; }
	std::shared_ptr<B> b;
};

struct B {
	~B() { std::cout << "B::~B()" << std::endl; }
	std::shared_ptr<A> a;
};

int main() {
	std::shared_ptr<A> a = std::make_shared<A>();
	std::shared_ptr<B> b = std::make_shared<B>();
	a->b = b;
	b->a = a;
	/// Будут ли вызваны деструкторы?
	return 0;
}
