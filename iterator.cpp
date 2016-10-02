#include <iostream>


class Storage {
public:
	Storage() {
		for (int i = 0; i < N; i++) {
			data[i] = i;
		}
	}
	
	// 1. Простейший вариант (для обычного массива он и является наиболее
	//    правильным и приблизительно в таком виде и сделан в stl)
	
	struct iterator {
		iterator(int* ptr) : _ptr(ptr) { }
		
		iterator& operator++() {
			++_ptr;
			return (*this);
		}
		
		iterator operator++(int) {
			iterator answer(*this);
			++(*this);
			return answer;
		}
		
		bool operator==(const iterator& other) const { return _ptr == other._ptr; }
		bool operator!=(const iterator& other) const { return !((*this) == other); }
		
		// нельзя изменить объект по этому итератору
		const int& operator*() const { return *_ptr; }
		// по этому можно
		int& operator*() { return *_ptr; }
		
		
	protected:
		int* _ptr;
	};
	iterator begin() { return data; }
	iterator end() { return data + N; }
	
	
	struct reverse_iterator : public iterator {
		// Использовать конструктор из базового класса
		using iterator::iterator;
		
		iterator& operator++() {
			--_ptr;
			return (*this);
		}
		
		iterator operator++(int) {
			iterator answer(*this);
			++(*this);
			return answer;
		}
	};
	reverse_iterator rbegin() { return data + N - 1; }
	reverse_iterator rend() { return data - 1; }
	
	
	
	// 2. Ещё вариант (такая идея используется для более сложных контейнеров)
	/*
	struct iterator {
		iterator(Storage* s, size_t index) : storage(s), _index(index) { }
		
		iterator& operator++() {
			++_index;
			return (*this);
		}
		
		iterator operator++(int) {
			iterator answer(*this);
			++(*this);
			return answer;
		}
		
		bool operator==(const iterator& other) const {
			if (storage != other.storage) { return false; }
			return _index == other._index;
		}
		bool operator!=(const iterator& other) const {
			return !((*this) == other);
		}
		
		// нельзя изменить объект по этому итератору
		const int& operator*() const { return storage->data[_index]; }
		// по этому можно
		int& operator*() { return storage->data[_index]; }
		
		
	protected:
		Storage* storage;
		size_t _index;
	};
	iterator begin() { return iterator(this, 0); }
	iterator end() { return iterator(this, N); }
	
	
	struct reverse_iterator : public iterator {
		// Использовать конструктор из базового класса
		using iterator::iterator;
		
		iterator& operator++() {
			--_index;
			return (*this);
		}
		
		iterator operator++(int) {
			iterator answer(*this);
			++(*this);
			return answer;
		}
	};
	reverse_iterator rbegin() { return reverse_iterator(this, N - 1); }
	reverse_iterator rend() { return reverse_iterator(this, -1); }
	*/
	
	
	// 3. Наиболее быстрая и адекватная в данной ситуации реализация
	//    (но уже не позволяет сделать реверс-итератор)
	/*
	using iterator = int*;
	iterator begin() { return data; }
	iterator end() { return data + N; }
	*/
	
	
private:
	static const int N = 10;
	int data[N];
	
};


int main() {
	Storage s;
	
	// Итерация -- это способ пройти по какому-либо хранилищу,
	// не вдаваясь в его внутреннюю структуру
	for (Storage::iterator iter = s.begin(); iter != s.end(); ++iter) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
	
	std::cout << "-------------------" << std::endl;
	
	
	// То же самое, только немного красоты и удобства из C++11
	for (int i : s) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	
	std::cout << "-------------------" << std::endl;
	
	
	// Итерация в обратном порядке (для варианта 3 закомментировать)
	for (Storage::reverse_iterator iter = s.rbegin(); iter != s.rend(); ++iter) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
	
	
	// Здесь используется неконстантный итератор
	std::cout << "Changing the values ..." << std::endl;
	for (Storage::iterator iter = s.begin(); iter != s.end(); ++iter) {
		*iter = 5;
	}
	for (int i : s) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	
	return 0;
}

