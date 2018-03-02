#ifndef FACTORY_EXAMPLES_DERIVED1_HPP
#define FACTORY_EXAMPLES_DERIVED1_HPP

#include "Base.hpp"

class Derived1 : public Base {
public:
    virtual void foo() override;

private:
    static bool unused_register_helper;
};


#endif //FACTORY_EXAMPLES_DERIVED1_HPP
