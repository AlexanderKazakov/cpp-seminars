#include "Derived2.hpp"
#include "Factory.hpp"

using namespace std;


bool Derived2::unused_register_helper = Factory::registerMe("Derived2", []()-> std::shared_ptr<Base> {
    return std::make_shared<Derived2>();
});
// can reduce further code duplication with macro


void Derived2::foo() {
    cout << "Derived2::foo()" << endl;
}
