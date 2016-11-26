#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

template<typename IntContainer>
void viewContainer() {
	const std::initializer_list<int> input = {
		7, 10, 4, 1, 2, 3, 4, 5, 9, 9, 8, 6,
	};
	IntContainer container(input);
	for (int item : container) { std::cout << item << " "; }
	std::cout << std::endl;
}

int main() {
	std::cout << "vector:" << std::endl;
	viewContainer<std::vector<int>>();
	std::cout << "set:" << std::endl;
	viewContainer<std::set<int>>();
	std::cout << "unordered_set:" << std::endl;
	viewContainer<std::unordered_set<int>>();
	return 0;
}
