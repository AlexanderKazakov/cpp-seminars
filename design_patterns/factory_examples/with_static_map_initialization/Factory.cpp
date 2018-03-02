#include "Factory.hpp"


std::shared_ptr<Base> Factory::create(const std::string& name) {
    auto iter = getVariants().find(name);
    if (iter != getVariants().end()) {
        return iter->second();
    }
    throw FactoryException(name);
}

bool Factory::registerMe(const std::string& name, const CreatorFunc& creator) {
    return getVariants().insert({name, creator}).second;
}

Factory::Map& Factory::getVariants() {
    // "Construct On First Use Idiom"
    static Map* variants = new Map(); // yes, this is a leak
    return *variants;
}


