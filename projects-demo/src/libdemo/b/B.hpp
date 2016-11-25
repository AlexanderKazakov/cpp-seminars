// Ещё один способ избежать "multiple definition of class B"
#pragma once

#include "libdemo/a/A.hpp"

namespace demo {

class B {
public:
	void print() const;
private:
	A a;
};

} // namespace demo

