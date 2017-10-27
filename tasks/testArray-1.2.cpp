#include <cassert>
#include <iostream>
#include "IntArray.hpp"

// А так можно посмотреть на работу программы, если в качестве 
// IntArray будет использован std::vector<int> 
// (закомментив сначала #include "IntArray.hpp"):
// #include <vector>
// using IntArray = std::vector<int>;

/// Задание по курсу. Написать класс-обёртку вокруг динамического массива целых чисел
/// Реализовать класс хранения данных, поддерживающий все операции, чтобы программа компилировалась
/// и отрабатывала без ошибок.
/// Ваш класс должен быть расположен в файле "IntArray.hpp", называться IntArray 
/// и находиться в той же папке, где и данный файл.
/// Тогда для компиляции можно использовать, к примеру
/// "g++ -std=c++11 -Wall testArray-1.cpp"


void testConstructorsAndAssignment() {
	IntArray a;
	IntArray b(10000);
	IntArray c(5, 1);
	IntArray d(b);
	IntArray e({1, 1, 1, 1, 1});
	
	assert(a.size() == 0);
	assert(b == d);
	assert(b.size() == 10000);
	assert(c == e);
	
	IntArray tmp = c;
	b = c;
	assert(b == c);
	b = e;
	assert(c == tmp);
	
	b = b;
	assert(b == e);
	
	IntArray oldA = a;
	IntArray oldB = b;
	swap(a, b);
	assert(b == oldA);
	assert(a == oldB);
}


void testOperators() {
	IntArray a = {1, 2, 3};
	IntArray b = {1};
	IntArray c = {2, 0, 0};
	
	assert( !(a == b) );
	assert(a != b);
	
	assert(b < a);
	assert(b <= a);
	assert(c > a);
	assert(c > b);
}


void testAccess() {
	const IntArray a = {1, 2, 3};
	assert(a[0] == 1); assert(a[1] == 2); assert(a[2] == 3);
	assert(a.at(0) == 1); assert(a.at(1) == 2); assert(a.at(2) == 3);
	
	IntArray b;
	b.assign({7, 7, 7, 7, 7});
	assert(b[4] == 7);
	assert(b.at(4) == 7);
	b.assign(a.begin(), a.end());
	assert(b == a);
	b.clear();
	assert(b.size() == 0);
}


void testPushPop() {
	IntArray a;
	a.push_back(5);
	a.push_back(6);
	assert(a[0] == 5 && a[1] == 6);
	a.pop_back();
	assert(a.size() == 1);
	a.pop_back();
	assert(a.size() == 0);
}


void testIteration() {
	IntArray a;
	assert(a.begin() == a.end());
	assert(a.rbegin() == a.rend());
	
	a = IntArray(10000);
	for (int i = 0; i < 10000; i++) {
		a[i] = i;
	}
	
	int counter = 0;
	IntArray::iterator aIter;
	for (aIter = a.begin(); aIter != a.end(); ++aIter) {
		assert(*aIter == counter);
		++counter;
	}
	
	for (IntArray::reverse_iterator aReverseIter = a.rbegin();
			aReverseIter != a.rend(); ++aReverseIter) {
		--counter;
		--aIter;
		assert(*aReverseIter == counter);
	}
	assert(aIter == a.begin());
}


void testIterationConstness() {
	IntArray a(10);
	int counter = 0;
	for (auto& i : a) {
		i = counter++;
	}
	const IntArray b = a;
	counter = 0;
	for (const auto& i : b) {
		counter += i;
	}
	assert(counter == 45);
}


int main() {
	
	testConstructorsAndAssignment();
	testOperators();
	testAccess();
	testPushPop();
	testIteration();
	testIterationConstness();
	
	return 0;
}

