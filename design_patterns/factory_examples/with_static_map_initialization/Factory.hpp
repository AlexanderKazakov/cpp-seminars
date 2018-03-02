#ifndef FACTORY_EXAMPLES_FACTORY_HPP
#define FACTORY_EXAMPLES_FACTORY_HPP

#include <memory>
#include <map>
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
    typedef std::shared_ptr<Base> (*CreatorFunc)();
    typedef std::map<std::string, CreatorFunc> Map;
    
    static std::shared_ptr<Base> create(const std::string& name);
    
    static bool registerMe(const std::string& name, const CreatorFunc& creator);

private:
    // It can not be just a "static Map", because of
    // "static initialization order fiasco" possibility:
    // https://isocpp.org/wiki/faq/ctors#static-init-order
    static Map& getVariants();
};


#endif //FACTORY_EXAMPLES_FACTORY_HPP
