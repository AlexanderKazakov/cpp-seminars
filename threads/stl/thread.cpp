#include <iostream>
#include <thread>


void threadFunction(const int q, int& v) {
	std::cout << "before: " << v << ", ";
	v += q;
	std::cout << "after: " << v << std::endl;
}
 
int main() {
	int v = 0;
	/// Передача по ссылке требует явного приведения -- std::ref()
	std::thread t(threadFunction, 3, std::ref(v));
	t.join();
	std::cout << "In main(): v == " << v << std::endl;
	return 0;
}

