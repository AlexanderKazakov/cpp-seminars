#include <iostream>
#include <memory>
#include <cassert>

/// Forward declaration
struct B;

struct A {
	~A() { std::cout << "A::~A()" << std::endl; }
	void doSmth() { std::cout << "A::doSmth()" << std::endl; }
	std::shared_ptr<B> b;
};

struct B {
	~B() { std::cout << "B::~B()" << std::endl; }
	std::weak_ptr<A> a;
	void f() {
		/// Пример работы с weak_ptr:
		std::shared_ptr<A> sp = a.lock();
		assert(sp);
		sp->doSmth();
	}
};

int main() {
	std::shared_ptr<A> a = std::make_shared<A>();
	std::shared_ptr<B> b = std::make_shared<B>();
	a->b = b;
	b->a = a;
	b->f();
	/// Будут ли теперь вызваны деструкторы?
	return 0;
}
