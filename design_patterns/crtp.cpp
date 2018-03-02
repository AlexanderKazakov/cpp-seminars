#include <iostream>

using namespace std;

// CRTP - curious recurring template pattern

template<typename Derived>
struct Base {
    void f() {
        Derived& d = static_cast<Derived&>(*this);
        // Из базового класса вызываются методы класса-наследника
        // без использования виртуальных функций:
        d.g(); d.h();
    }
};

struct Derived1 : Base<Derived1> {
    void g() {cout << "Derived1::g()" << endl;}
    void h() {cout << "Derived1::h()" << endl;}
};
struct Derived2 : Base<Derived2> {
    void g() {cout << "Derived2::g()" << endl;}
    void h() {cout << "Derived2::h()" << endl;}
};

int main() {
    // И тем не менее это разные классы, их невозможно хранить в
    // одном контейнере или передавать в одну и ту же функцию,
    // как было бы, если бы использовался обычный динамический полиморфизм
    Derived1().f();
    Derived2().f();
    
    // Задание: переписать первый пример type erasure
    // c использованием CRTP.
    // (не дублировать функцию clone в каждом наследнике).
    // Ещё пример использования CRTP -- std::enable_shared_from_this.
    return 0;
}
