#include <iostream>
#include <map>
#include <unordered_map>


int main() {
	std::map<std::string, int> map = {
		{"ghk", 1}, {"def", 2}, {"abc", 3}
	};
	for (const std::pair<std::string, int> p : map) {
		std::cout << p.first << ": " << p.second << std::endl;
	}
	std::cout << "-----------------------------" << std::endl;
	
	map.insert({"bbb", 4});
	for (const std::pair<std::string, int> p : map) {
		std::cout << p.first << ": " << p.second << std::endl;
	}
	std::cout << "-----------------------------" << std::endl;
	
	std::unordered_map<std::string, int> umap(map.begin(), map.end());
	umap.insert({"zzz", 5});
	for (const std::pair<std::string, int> p : umap) {
		std::cout << p.first << ": " << p.second << std::endl;
	}
	std::cout << "-----------------------------" << std::endl;
	return 0;
}
