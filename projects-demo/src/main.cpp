#include <libdemo/a/A.hpp>
#include <libdemo/b/B.hpp>
#include <libdemo/c/c.hpp>


int main() {
	demo::A a;
	a.print();
	
	demo::B b;
	b.print();
	
	demo::foo();
	
	return 0;
}

