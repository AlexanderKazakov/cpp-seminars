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
	PolymorphicDer* pmderPtrToDer = static_cast<PolymorphicDer*>(pmbasePtrToDer);
	std::cout << "Der ptr to Der : " << pmderPtrToDer <<  std::endl;
	
	// Приведение к указателю на неверный тип возвращает тот же указатель.
	// Дальнейшее поведение при использовании значения по указателю не определено
	PolymorphicDer* pmderPtrToBase = static_cast<PolymorphicDer*>(pmbaseP);
	std::cout << "Der ptr to Base : " << pmderPtrToBase <<  std::endl;
	
	// Статическое приведение типов возможно для любого разрешённого приведения типов
	Base* basePtrToDer = new Der();
	static_cast<Der*>(basePtrToDer);
	
	// Статическое приведение типов для наследников разных базовых классов запрещено
	// Код ниже не скомпилируется "invalid static_cast"
//	PolymorphicDer2* pmder2P = static_cast<PolymorphicDer2*>(new PolymorphicDer());
//	std::cout << "Der2 ptr to Der : " << pmder2P <<  std::endl;
	
	
	std::cout << "-------------------------------" << std::endl;
	
	
	PolymorphicBase& pmbaseR = pmbase;
	PolymorphicBase& pmbaseRefToDer = pmder;
	
	// To же самое для ссылок
	PolymorphicDer& pmderRefToDer = static_cast<PolymorphicDer&>(pmbaseRefToDer);
	
	// Статическое приведение к ссылке на неверный тип не выдаст исключения
	// Дальнейшее поведение при использовании значения по ссылке не определено
	PolymorphicDer& pmderRefToBase = static_cast<PolymorphicDer&>(pmbaseR);
	
	
	return 0;
}

