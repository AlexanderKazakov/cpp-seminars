#include <iostream>
#include <memory>
#include <cassert>

/// std::shared_ptr -- наиболее используемый "умный указатель" -- 
/// обёртка вокруг обычного указателя на некий объект, 
/// которая ведёт подсчёт (use_count) своих собратьев,
/// ссылающихся на данный объект.
/// Когда этот счётчик приходит к нулю, последний вызывает
/// удаление объекта.

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
	std::cout << "In f, firstly: b.use_count() == " << b.use_count() << std::endl;
	/// Аналогично dynamic_cast (см. также static_pointer_cast)
	std::shared_ptr<D> d = std::dynamic_pointer_cast<D>(b);
	std::cout << "In f, after d creation: b.use_count() == " << b.use_count() << std::endl;
	std::cout << "In f, after d creation: d.use_count() == " << d.use_count() << std::endl;
	assert(d);
	d->foo();
}

int main() {
	std::shared_ptr<B> b;
	std::cout << "In main, empty: b.use_count() == " << b.use_count() << std::endl;
	b = std::make_shared<D>();
	std::cout << "In main, before f: b.use_count() == " << b.use_count() << std::endl;
	f(b);
	std::cout << "In main, after f: b.use_count() == " << b.use_count() << std::endl;
	return 0;
}
