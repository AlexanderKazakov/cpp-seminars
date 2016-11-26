#include <iostream>
#include <typeinfo>


class Base {};
class Der : public Base {};

class PolymorphicBase { public: virtual ~PolymorphicBase() {} };
class PolymorphicDer : public PolymorphicBase {};

template<typename T> class TemplatedClass {};


int main() {
	bool b, b2;
	bool* bp;
	std::cout << "bool : " << typeid(b).name() << std::endl;
	std::cout << "another bool : " << typeid(b2).name() << std::endl;
	std::cout << "pointer to bool: " << typeid(bp).name() << std::endl;
	
	char c;
	char* cp;
	std::cout << "char : " << typeid(c).name() << std::endl;
	std::cout << "pointer to char: " << typeid(cp).name() << std::endl;
	
	int i;
	int& ri = i;
	std::cout << "int : " << typeid(i).name() << std::endl;
	std::cout << "reference to int : " << typeid(ri).name() << std::endl;
	
	std::cout << "float : " << typeid(float).name() << std::endl;
	
	std::cout << "----------------------------------" << std::endl;
	
	
	Base base;
	Base* baseP = &base;
	Der der;
	Der* derP = &der;
	
	Base* basePtrToDerObj = derP;
	
	std::cout << "Base : " << typeid(base).name() << std::endl;
	std::cout << "Der : " << typeid(der).name() << std::endl;
	std::cout << "Value by Base pointer to Base obj : " << typeid(*baseP).name() << std::endl;
	std::cout << "Value by Der pointer to Der obj : " << typeid(*derP).name() << std::endl;
	std::cout << "Value by Base pointer to Der obj : " << typeid(*basePtrToDerObj).name() << std::endl;
	
	
	std::cout << "----------------------------------" << std::endl;
	
	PolymorphicBase pmBase;
	PolymorphicBase* pmbaseP = &pmBase;
	PolymorphicDer pmDer;
	PolymorphicDer* pmderP = &pmDer;
	PolymorphicBase* pmbasePtrToPolymorhpicDerObj = pmderP;
	
	std::cout << "Value by PolymorphicBase pointer to PolymorphicBase obj : " 
			<< typeid(*pmbaseP).name() << std::endl;
	std::cout << "Value by PolymorphicDer pointer to PolymorphicDer obj : " 
			<< typeid(*pmderP).name() << std::endl;
	std::cout << "Value by PolymorphicBase pointer to PolymorphicDer obj : "
			<< typeid(*pmbasePtrToPolymorhpicDerObj).name() << std::endl;
	
	
	std::cout << "----------------------------------" << std::endl;
	
	std::cout << "TemplatedClass<int> : " << typeid(TemplatedClass<int>).name() << std::endl;
	std::cout << "TemplatedClass<char> : " << typeid(TemplatedClass<char>).name() << std::endl;
	
	return 0;
}
