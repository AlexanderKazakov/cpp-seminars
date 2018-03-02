#include <iostream>
#include <thread>

using namespace std;

// Singleton -- "одиночка"
class Singleton {
public:
    static Singleton& getInstance() {
        cout << "Singleton::getInstance()" << endl;
        // Создаётся только один экземпляр класса на всю программу.
        // Да, в C++11 это потокобезопасно.
        static Singleton instance;
        return instance;
    }
    
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&) = delete;
    
    void foo() {
        cout << "Singleton::foo()" << endl;
    }
    
protected:
    Singleton() {
        cout << "Singleton::Singleton()" << endl;
    }
    ~Singleton() {
        cout << "Singleton::~Singleton()" << endl;
    }
};

void bar() {
    // Вызываем из любой точки программы без необходимости
    // таскать ссылки или указатели через аргументы функций
    Singleton::getInstance().foo();
}

int main() {
    Singleton::getInstance().foo();
    std::thread t([](){Singleton::getInstance().foo();});
    bar();
    t.join();
    return 0;
}
