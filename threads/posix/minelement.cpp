#include <iostream>
#include <algorithm>
#include <chrono>
#include <cassert>
#include <pthread.h>


template<typename RaIter>
RaIter minElement(RaIter begin, const RaIter end) {
	RaIter ans = begin;
	for (; begin != end; ++begin) {
		if (*ans > *begin) { ans = begin; }
	}
	return ans;
}


/// Вспомогательная структура для передачи аргументов в функцию потока
typedef std::vector<int> VecInt;
typedef VecInt::iterator Iterator;
struct ThreadHelper {
	Iterator first;
	Iterator last;
	Iterator min;
};

/// Такова должна быть сигнатура функции для вызова в отдельном POSIX-потоке
void* minElementPthread(void* arg) {
	ThreadHelper* helper = (ThreadHelper*)(arg);
	helper->min = minElement(helper->first, helper->last);
	return NULL;
}


int main() {
	const size_t N = 100000000;
	VecInt v(N);
	srand(time(0));
	for (int& i : v) { i = rand(); }
	
	/// Последовательно
	auto t1 = std::chrono::high_resolution_clock::now();
	
	Iterator minSequence = minElement(v.begin(), v.end());
	
	auto t2 = std::chrono::high_resolution_clock::now();
	std::cout << "Time of sequence calculation, seconds = " <<
			std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() / 1e+6 << std::endl;
	
	
	/// В два потока
	t1 = std::chrono::high_resolution_clock::now();
	
	pthread_t thread1;
	ThreadHelper firstHalf = {v.begin(), v.begin() + N / 2, v.end()};
	int errorCode = pthread_create(&thread1, NULL, minElementPthread, (void*)(&firstHalf));
	if (errorCode) {
		std::cerr << "Pthread error for the first thread code: " << errorCode << std::endl;
		return -1;
	}
	pthread_t thread2;
	ThreadHelper secondHalf = {v.begin() + N / 2 + 1, v.end(), v.end()};
	errorCode = pthread_create(&thread2, NULL, minElementPthread, (void*)(&secondHalf));
	if (errorCode) {
		std::cerr << "Pthread error for the second thread code: " << errorCode << std::endl;
		return -1;
	}
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	Iterator minParallel = (*firstHalf.min < *secondHalf.min) ? firstHalf.min : secondHalf.min;
	
	t2 = std::chrono::high_resolution_clock::now();
	std::cout << "Time of two threads calculation, seconds = " <<
			std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() / 1e+6 << std::endl;
	
	
	/// С помощью стандартной библиотеки
	t1 = std::chrono::high_resolution_clock::now();

	Iterator minStd = std::min_element(v.begin(), v.end());

	t2 = std::chrono::high_resolution_clock::now();
	std::cout << "Time of standard library calculation, seconds = " <<
			std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() / 1e+6 << std::endl;
	
	
	assert(minParallel == minSequence);
	assert(minParallel == minStd);
	return 0;
}

