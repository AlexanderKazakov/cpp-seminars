#ifndef FACTORY_EXAMPLES_DERIVED2_HPP
#define FACTORY_EXAMPLES_DERIVED2_HPP

#include "Base.hpp"

class Derived2 : public Base {
public:
    virtual void foo() override;

private:
    static bool unused_register_helper;
};


#endif //FACTORY_EXAMPLES_DERIVED2_HPP
