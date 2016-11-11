#include <iostream>
#include <vector>
#include <algorithm>
#include <future>

typedef std::vector<int> VecInt;
typedef VecInt::iterator Iter;

/// Пример с cppreference.com
/// std::async -- это обёртка, позволяющая вызвать
/// асинхронное исполнение функции.
/// 
/// С аргументом std::launch::async она запускает отдельный поток,
/// то есть представляет собой некую обёртку вокруг треда.
/// 
/// Также см. std::launch::deferred -- с этим аргументом осуществляется
/// так называемое "ленивое" вычисление (которое производится 
/// только в тот момент, когда непосредственно нужен результат)

int parallel_sum(Iter beg, Iter end) {
	auto len = end - beg;
	if(len < 1000) { return std::accumulate(beg, end, 0); }
	Iter mid = beg + len / 2;
	/// Рекурсия
	auto handle = std::async(std::launch::async, parallel_sum, mid, end);
	int sum = parallel_sum(beg, mid);
	return sum + handle.get();
}

int main() {
	std::vector<int> v(10000, 1);
	std::cout << "The sum is " << parallel_sum(v.begin(), v.end()) << '\n';
	return 0;
}

