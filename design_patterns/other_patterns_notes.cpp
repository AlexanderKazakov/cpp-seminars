#include <iostream>
#include <vector>

using namespace std;


int main() {
    // proxy access pattern: v[1] -- это не bool&
    vector<bool> v = {true, false};
    v[1] = true;
    
    // small objects optimization
    struct string {
        union {
            size_t size;
            char c[sizeof(size_t)];
        };
        char* ptr;
    };
    
    // RAII -- resource acquisition is initialization:
    // в конструкторе создаём/выделяем/лочим/запускаем,
    // в деструкторе уничтожаем/освобождаем/разблокируем/останавливаем.
    // Что обеспечивает безопасность при исключениях или просто
    // невнимательности -- не нужно следить за освобождением ресурса
    // во всех ветках исполнения. Примеры:
    // smart pointers, lock guards, file streams, ...
    
    // Pointer to implementation:
    // скрыть реализацию, не перекомпилировать клиентский код.
    class Abc {
    public:
        // unchangeable interface ...
    private:
        class AbcImpl* implementation;
    };
    
    // Named constructors -- защита на этапе компиляции от создания объектов
    // с невалидными параметрами. В примере ниже структуру A можно создавать только с 1 или 2
    struct A {
        static A createA1() {return A(1);}
        static A createA2() {return A(2);}
    private:
        A(int v) : _v(v) {}
        int _v;
    };
    
    // Attorney-Client -- возможность выделить из private-методов и членов класса-клиента
    // некое подмножество, которое возможно вызывать через дополнительный friend-класс Attorney(представитель)
    class Client { void a() {}; void b() {}; friend class Attorney; };
    struct Attorney { void callA(Client& client) {client.a();}; };
    
    // Strategy -- алгоритм заключается внутрь класса, подмена алгоритма
    // сводится к подмене класса-контейнера алгоритма. Реализуется через
    // наследование, шаблоны, композицию, ...
    // Пример -- Allocator в контейнерах stl
    
    // Шаблонный метод (или non-virtual interface):
    // Гарантирует выполнение всеми наследниками определённых действий при вызове виртуальной функции
    struct Base {
        void foo() {
            cout << "Common actions for all derived classes before foo" << endl;
            fooImpl();
            cout << "Common actions for all derived classes after foo" << endl;
        }
    protected:
        virtual void fooImpl() = 0; // to be implemented in derived classes
    };
    
    return 0;
}
