#include <iostream>
#include <cassert>


/// Более-менее адекватная реализация того, что было на занятии
/// по виртуальным функциям. Собирать с "-std=c++11"


/// Абстрактный класс (ещё иногда называется интерфейс)
/// для всех типов точек
class P {
public:
    /// Число измерений
    virtual int getDimensions() = 0;
    /// Вернёт i-ю координату точки
    virtual double getCoordinate(const int i) = 0;
    /// Прибавить к точке точку (подвинуть точку)
    virtual void add(P* another) = 0;
    /// Написать точку
    virtual void print() = 0;
};


/// Двумерная точка
class P2 : public P {
public:
    
    P2(const double x, const double y) {
        d[0] = x; d[1] = y;
    }
    
    virtual int getDimensions() override {
        return 2;
    }
    
    virtual double getCoordinate(const int i) override {
        assert(i >= 0); assert(i < getDimensions());
        return d[i];
    }
    
    virtual void add(P* another) override {
        assert(getDimensions() == another->getDimensions());
        d[0] += another->getCoordinate(0);
        d[1] += another->getCoordinate(1);
    }
    
    virtual void print() {
        std::cout << getCoordinate(0) << "\t" << getCoordinate(1) << std::endl;
    }
    
    
private:
    /// Это идеологически верно держать в private
    double d[2];
    
};


/// Трёхмерная точка
class P3 : public P {
public:
    
    P3(const double x, const double y, const double z) {
        d[0] = x; d[1] = y; d[2] = z;
    }
    
    virtual int getDimensions() override {
        return 3;
    }
    
    virtual double getCoordinate(const int i) override {
        assert(i >= 0); assert(i < getDimensions());
        return d[i];
    }
    
    virtual void add(P* another) override {
        assert(getDimensions() == another->getDimensions());
        d[0] += another->getCoordinate(0);
        d[1] += another->getCoordinate(1);
        d[2] += another->getCoordinate(2);
    }
    
    virtual void print() {
        std::cout 
                << getCoordinate(0) << "\t"
                << getCoordinate(1) << "\t"
                << getCoordinate(2) << std::endl;
    }
    
    
private:
    /// Это идеологически верно держать в private
    double d[3];
    
};



/// В момент компиляции неизвестно, двумерные это точки или трёхмерные
/// (или кто-то ошибся и отправил точки с разными измерениями)
P* add(P* p1, P* p2) {
    
    int dim = p1->getDimensions();
    assert(dim == p2->getDimensions());
    
    /// Внимание: это характерный пример возможной утечки памяти, так как
    /// мы создаём через new объект, который потом кто-то должен будет удалить
    if (dim == 2) {
        return new P2(p1->getCoordinate(0) + p2->getCoordinate(0),
                      p1->getCoordinate(1) + p2->getCoordinate(1));
        
    } else if (dim == 3) {
        return new P3(p1->getCoordinate(0) + p2->getCoordinate(0),
                      p1->getCoordinate(1) + p2->getCoordinate(1),
                      p1->getCoordinate(2) + p2->getCoordinate(2));
        
    } else {
        assert(false); ///< we don't know what type is it
    }
    
}



int main() {
	
	P* p2 = new P2(1, 2);
	p2->print();
	P* p3 = new P3(1, 2, 3);
	p3->print();
	
	p2->add(p2);
	p2->print();
	p3->add(p3);
	p3->print();
	
	// this would be aborted:
//	p2->add(p3);
	
	P* p = add(p2, p2);
	p->print();
	
	delete p; //< удаляем объект, созданный в функции add
	delete p2;
	delete p3;
	return 0;
}
