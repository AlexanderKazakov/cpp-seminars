#ifndef FACTORY_EXAMPLES_FACTORY_HPP
#define FACTORY_EXAMPLES_FACTORY_HPP

#include <memory>
#include "Base.hpp"

struct FactoryException : std::exception {
    FactoryException(const std::string& name) :
            unknown_class_name(name), _wt("Unknown class name: " + name) {}
    
    virtual const char* what() const noexcept override {
        return _wt.c_str();
    }

private:
    const std::string unknown_class_name;
    const std::string _wt;
};


class Factory {
public:
    std::shared_ptr<Base> create(const std::string& name) const;
};


#endif //FACTORY_EXAMPLES_FACTORY_HPP
