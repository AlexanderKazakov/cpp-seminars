#include <iostream>


class Base {};
class Der : public Base {};

class PolymorphicBase { public: virtual ~PolymorphicBase() {} };
class PolymorphicDer : public PolymorphicBase {};

class PolymorphicBase2 { public: virtual ~PolymorphicBase2() {} };
class PolymorphicDer2 : public PolymorphicBase2 {};


int main() {
	
	PolymorphicBase pmbase;
	PolymorphicDer pmder;
	
	
	PolymorphicBase* pmbaseP = &pmbase;
	std::cout << "Base ptr to Base : " << pmbaseP <<  std::endl;
	
	PolymorphicBase* pmbasePtrToDer = &pmder;
	std::cout << "Base ptr to Der : " << pmbasePtrToDer <<  std::endl;
	
	// Теперь мы имеем указатель на объект производного, а не базового типа:
	PolymorphicDer* pmderPtrToDer = dynamic_cast<PolymorphicDer*>(pmbasePtrToDer);
	std::cout << "Der ptr to Der : " << pmderPtrToDer <<  std::endl;
	
	// Приведение к указателю на неверный тип возвращает нуль
	PolymorphicDer* pmderPtrToBase = dynamic_cast<PolymorphicDer*>(pmbaseP);
	std::cout << "Der ptr to Base : " << pmderPtrToBase <<  std::endl;
	
	PolymorphicDer2* pmder2P = dynamic_cast<PolymorphicDer2*>(new PolymorphicDer());
	std::cout << "Der2 ptr to Der : " << pmder2P <<  std::endl;
	
	
	
	std::cout << "-------------------------------" << std::endl;
	
	
	PolymorphicBase& pmbaseR = pmbase;
	PolymorphicBase& pmbaseRefToDer = pmder;
	
	// To же самое для ссылок
	PolymorphicDer& pmderRefToDer = dynamic_cast<PolymorphicDer&>(pmbaseRefToDer);
	
	// Приведение к ссылке на неверный тип генерирует исключение
	try {
		PolymorphicDer& pmderRefToBase = dynamic_cast<PolymorphicDer&>(pmbaseR);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	
	// Динамическое приведение типов возможно только для классов,
	// имеющих виртуальные функции. Код ниже не скомпилируется 
	// "source type is not polymorphic"
//	Base* basePtrToDer = new Der();
//	dynamic_cast<Der*>(basePtrToDer);
	
	return 0;
}

