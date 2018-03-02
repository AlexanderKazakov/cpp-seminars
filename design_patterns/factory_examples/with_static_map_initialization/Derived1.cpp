#include "Derived1.hpp"
#include "Factory.hpp"

using namespace std;


bool Derived1::unused_register_helper = Factory::registerMe("Derived1", []()-> std::shared_ptr<Base> {
    return std::make_shared<Derived1>();
});


void Derived1::foo() {
    cout << "Derived1::foo()" << endl;
}
