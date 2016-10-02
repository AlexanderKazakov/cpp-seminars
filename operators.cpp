#include <iostream>
#include <cmath>


class X {
public:
	X(double value) : d(value) { }
	
	double getValue() const { return d; }
	
	
	// pre-increment operator
	// Возвращается ссылка на объект после прибавления
	X& operator++() {
		move(1);
		return (*this);
	}
	
	// post-increment operator
	// Возвращается значение объекта до прибавления
	// int в аргументе -- просто для того, чтобы различать с пре-инкрементом
	X operator++(int) {
		X answer(*this);
		++(*this);
		return answer;
	}
	
	// Обратите внимание -- везде повторное использование кода,
	// которое к тому же гарантирует корректность наших операций,
	// то есть x += b и x = x + b -- это одно и то же.
	X& operator+=(const X& rhs) {
		move(rhs.getValue());
		return *this;
	}
	friend X operator+(X lhs, const X& rhs) {
		lhs += rhs;
		return lhs;
	}
	
	// А как бы вы реализовали вариант с минусом?
	
	
	// Всегда, когда определена какая-то часть операторов сравнения,
	// все они должны сводиться к одному (иначе напишите функцию)
	friend bool operator< (const X& lhs, const X& rhs) { return lhs.d < rhs.d; }
	friend bool operator!=(const X& lhs, const X& rhs) { return	rhs < lhs || lhs < rhs; }
	friend bool operator==(const X& lhs, const X& rhs) { return ! (lhs != rhs); }
	friend bool operator> (const X& lhs, const X& rhs) { return	rhs < lhs; }
	friend bool operator<=(const X& lhs, const X& rhs) { return ! (lhs > rhs); }
	friend bool operator>=(const X& lhs, const X& rhs) { return ! (lhs < rhs); }
	
	// Всегда, когда оператор не делает в точности то и только то,
	// что от него подразумевается, заместо него надо делать функцию
	friend bool approximatelyEqual(const X& lhs, const X& rhs) {
		return fabs(lhs.d - rhs.d) < 1e-14;
	}
	
	
private:
	double d;
	void move(double change) { d = d + change; }
};


int main() {
	
	X a(0);
	std::cout << a.getValue() << std::endl;
	
	a++;
	std::cout << a.getValue() << std::endl;
	++a;
	std::cout << a.getValue() << std::endl;
	
	
	std::cout << "--------------" << std::endl;
	
	
	X b(0);
	std::cout << b.getValue() << std::endl;
	
	std::cout << (++b).getValue() << std::endl;
	std::cout << b.getValue() << std::endl;
	
	std::cout << (b++).getValue() << std::endl;
	std::cout << b.getValue() << std::endl;
	
	
	std::cout << "--------------" << std::endl;
	
	
	// Хороший повод для убийства
	/*
	X c(0);
	std::cout << (c++ + ++c + c++).getValue() << std::endl;
	std::cout << c.getValue() << std::endl;
	*/
	
	return 0;
}

