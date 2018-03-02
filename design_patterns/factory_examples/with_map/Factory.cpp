#include "Factory.hpp"
#include "Derived1.hpp"
#include "Derived2.hpp"


Factory::Factory() {
    variants.insert({"Derived1", []()->std::shared_ptr<Base>{
        return std::make_shared<Derived1>();}});
    variants.insert({"Derived2", []()->std::shared_ptr<Base>{
        return std::make_shared<Derived2>();}});
}

std::shared_ptr<Base> Factory::create(const std::string& name) const {
    auto iter = variants.find(name);
    if (iter != variants.end()) {
        return iter->second();
    }
    throw FactoryException(name);
}
