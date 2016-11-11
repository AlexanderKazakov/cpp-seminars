#include <iostream>
#include <thread>
#include <mutex>


class A {
public:
	/// Не потокобезопасно:
//	int counter() const { return _counter; }
//	void increaseCounter() { ++_counter; }
	
	/// Потокобезопасно
	int counter() const {
		int answer;
		_lock.lock();
		answer = _counter;
		_lock.unlock();
		return answer;
	}
	
	void increaseCounter() {
		_lock.lock();
		++_counter;
		_lock.unlock();
	}
	
	/// Вариант с использованием концепции RAII (см. Википедию) --
	/// в конструкторе lock_guard делается lock, в деструторе unlock.
	void increaseCounterWithLockGuard() {
		std::lock_guard<std::mutex> lockGuard(_lock);
		++_counter;
	}
	
private:
	int _counter = 0;
	/// mutable члены класса могут быть изменены в константных функциях
	mutable std::mutex _lock;
};

void threadFunction(A& a, const int threadNumber) {
	std::cout << "thread #" << threadNumber
			<< ": a.counter() before == " << a.counter() << std::endl;
	a.increaseCounterWithLockGuard();
	std::cout << "thread #" << threadNumber
			<< ": a.counter() after == " << a.counter() << std::endl;
}

int main() {
	A a;
	std::thread t1(threadFunction, std::ref(a), 1);
	std::thread t2(threadFunction, std::ref(a), 2);
	t2.join();
	t1.join();
	std::cout << "In main(): a.counter() == " << a.counter() << std::endl;
	return 0;
}

