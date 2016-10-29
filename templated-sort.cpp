#include <iostream>
#include <algorithm>


template<typename TRandomAccessIterator, typename TPredicate>
void customSort(
		TRandomAccessIterator first, TRandomAccessIterator last,
		TPredicate predicate) {
	/// Здесь должен быть ваш код -- сортировка пузырьковая или слиянием
	std::sort(first, last, predicate);
}


template<typename TIterator>
void printRange(TIterator first, TIterator last) {
	int counter = 0;
	for ( ; first != last; ++first) {
		std::cout << *first << " ";
		if (++counter > 100) {
			std::cout << "and so on ...";
			break;
		}
	}
	std::cout << std::endl;
}


template<typename T> bool customLess(const T& a, const T& b) { return a < b; }

template<typename T>
struct RuntimeLess {
	/// Ответ будет зависеть от флага, выставляемого в момент исполнения программы
	bool inverse = false;
	
	bool operator()(const T& a, const T& b) const {
		return inverse ? (a < b) : (a > b);
	}
};


int main() {
	const size_t N = 10;
	
	std::vector<int> stdvec(N);
	srand(time(0));
	for (int& i : stdvec) { i = rand() % N; }
	printRange(stdvec.begin(), stdvec.end());
	
	/// Благодаря шаблонизации возможны любые вызовы нашей функции,
	/// перечисленные ниже -- лишь бы при генерации и сборке компилятором 
	/// обычного кода из нашего шаблонного кода не возникало ошибок
	
	customSort(stdvec.begin(), stdvec.end(), customLess<int>);
	customSort(stdvec.begin(), stdvec.end(), RuntimeLess<int>());
	
	RuntimeLess<int> runtimeLess;
	customSort(stdvec.begin(), stdvec.end(), runtimeLess);
	printRange(stdvec.begin(), stdvec.end());
	
	runtimeLess.inverse = true;
	customSort(stdvec.begin(), stdvec.end(), runtimeLess);
	printRange(stdvec.begin(), stdvec.end());
	
	
	customSort(stdvec.begin(), stdvec.end(), std::greater<int>());
	printRange(stdvec.begin(), stdvec.end());
	
	customSort(stdvec.begin(), stdvec.end(), std::less<int>());
	printRange(stdvec.begin(), stdvec.end());
	
	customSort(stdvec.begin(), stdvec.end(), 
			[](const int& a, const int& b) { return a < b; });
	
	return 0;
}

