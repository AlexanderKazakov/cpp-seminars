// Способ избежать "multiple definition of class A"
#ifndef LIBDEMO_A_HPP
#define LIBDEMO_A_HPP

namespace demo {

class A {
public:
	void print() const;
};

} // namespace demo



#endif // LIBDEMO_A_HPP
