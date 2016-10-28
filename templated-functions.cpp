#include <iostream>
#include <algorithm>


template<typename TRandomAccessIterator>
void customSort(TRandomAccessIterator first, TRandomAccessIterator last) {
	std::sort(first, last);
}

template<typename TIterator>
inline void printRange(TIterator first, TIterator last) {
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


int main() {
	const size_t N = 10;
	
	std::vector<int> stdvec(N);
	srand(time(0));
	for (int& i : stdvec) { i = rand() % N; }
	
	printRange(stdvec.begin(), stdvec.end());
	
	std::sort(stdvec.begin(), stdvec.end());
	
	printRange(stdvec.begin(), stdvec.end());
	
	return 0;
}

