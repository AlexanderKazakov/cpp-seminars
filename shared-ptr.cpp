#include <iostream>
#include <memory>
#include <cassert>

class B {
public:
	virtual ~B() { std::cout << "B::~B()" << std::endl; }
};
class D : public B {
public:
	virtual ~D() { std::cout << "D::~D()" << std::endl; }
	void foo() { std::cout << "D::foo()" << std::endl; }
};

void f(std::shared_ptr<B> b) {
	/// Поведение аналогично dynamic_cast (см. также static_pointer_cast)
	std::shared_ptr<D> d = std::dynamic_pointer_cast<D>(b);
	assert(d);
	d->foo();
}

int main() {
	std::shared_ptr<B> b = std::make_shared<D>();
	f(b);
	return 0;
}
