#include <iostream>

/// Демонстрация наследования и виртуальных функций aka "полиморфизм".

/// Вариант 1 -- без виртуальных функций вообще.
/// В каждом классе есть своя функция print,
/// выбор вызываемой функции происходит на этапе компиляции
/// в зависимости от типа указателя.
/// Это -- статический полиморфизм
/// Результат "P P P"

class P {
public:
    void print() { std::cout << "P" << std::endl; }
};

class P2 : public P {
public:
    void print() { std::cout << "P2" << std::endl; }
};

class P3 : public P {
public:
    void print() { std::cout << "P3" << std::endl; }
};



/// Вариант 2 -- с виртуальными функциями,
/// которые имеют реализацию в каждом классе.
/// Выбор вызываемой функции происходит на этапе выполнения программы.
/// Это -- динамический полиморфизм
/// Результат "P P2 P3"
/*
class P {
public:
    /// Убрав здесь "virtual", получим вывод "P P P"
    virtual void print() { std::cout << "P" << std::endl; }
};

class P2 : public P {
public:
    /// Сейчас здесь слово "virtual" не критично, главное,
    /// чтобы оно было в базовом классе. 
    /// Но вообще крайне рекомендуется его здесь писать тоже
    virtual void print() { std::cout << "P2" << std::endl; }
};

class P3 : public P {
public:
    virtual void print() { std::cout << "P3" << std::endl; }
};
*/


/// Вариант 3 -- с виртуальными функциями,
/// которые имеют реализацию только в производных классах
/// Выбор вызываемой функции происходит на этапе выполнения программы.
/// Это -- тоже динамический полиморфизм
/// Результат "P2 P3"
/*
class P {
public:
    /// "pure virtual" - в этом классе нет её реализации,
    /// поэтому мы не можем создавать объекты этого класса
    /// Строка "P* base = new P();" сейчас должна сломаться
    virtual void print() = 0;
};

class P2 : public P {
public:
    virtual void print() { std::cout << "P2" << std::endl; }
};

class P3 : public P {
public:
    virtual void print() { std::cout << "P3" << std::endl; }
};
*/


/// Вариант 4 -- наиболее "правильный", на мой взгляд.
/// Требует компиляции с флагом "-std=c++11".
/// Здесь на этапе компиляции проверяется, действительно ли
/// реализация из производного класса закрывает базовую.
/// Выбор вызываемой функции происходит на этапе выполнения программы.
/*
class P {
public:
    virtual void print() { std::cout << "P" << std::endl; }
    /// или так:
//    virtual void print() = 0;
};

class P2 : public P {
public:
    virtual void print() override { std::cout << "P2" << std::endl; }
};

class P3 : public P {
public:
    virtual void print() override { std::cout << "P3" << std::endl; }
};
*/


int main() {
	
	/// Указатели на объекты разных производных классов можно хранить
	/// в одном массиве как указатели на объекты базового класса
	P* p[2];
	p[0] = new P2();
	p[1] = new P3();
	
	
	/// Это будет компилироваться только если в классе P 
	/// нет чисто виртуальных "= 0" функций. Иначе нельзя создать объект класса P
	P* base = new P();
	base->print();
	
	
	/// Здесь в зависимости от виртуальности будет вызвана
	/// либо базовая реализация (базовая print не virtual)
	/// либо реализация из наследника (базовая print должна быть virtual)
	p[0]->print();
	p[1]->print();
	
	
	delete p[0];
	delete p[1];
	return 0;
}
