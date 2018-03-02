#include "Factory.hpp"
#include "Derived1.hpp"
#include "Derived2.hpp"


std::shared_ptr<Base> Factory::create(const std::string& name) const {
    if (name == "Derived1") {
        return std::make_shared<Derived1>();
    } else if (name == "Derived2") {
        return std::make_shared<Derived2>();
    }
    throw FactoryException(name);
}
