#include <iostream>


class Data {
public:
	Data(size_t size = 0) :
			_size(size), data(_size ? new int[_size] : nullptr) {
		std::cout << "In plain constructor" << std::endl;
	}
	
	Data(std::initializer_list<int> list) : Data(list.size()) {
		std::cout << "In initializer_list constructor" << std::endl;
		int i = 0;
		for (int value : list) { data[i++] = value; }
	}
	
	Data(const Data& other) : Data(other._size) {
		std::cout << "In copy constructor" << std::endl;
		if (data) { std::copy(other.data, other.data + _size, data); }
	}
	
	
	~Data() noexcept {
		std::cout << "In destructor with data == " << data << std::endl;
		if (data) { delete [] data; }
	}
	
	
	Data& operator=(Data other) noexcept {
		std::cout << "In assignment operator" << std::endl;
		swap(*this, other);
		return (*this);
	}
	
	
	// Меняет два объекта местами
	friend void swap(Data& one, Data& other) noexcept {
		std::cout << "swapping " << one.data << " with " << other.data << std::endl;
		std::swap(one._size, other._size);
		std::swap(one.data, other.data);
	}
	
	// Оператор ввода-вывода
	friend std::ostream& operator<<(std::ostream& os, const Data& data) {
		os << "data == " << data.data << "\tvalues == ";
		for (size_t i = 0; i < data._size; i++) { os << data.data[i] << ", "; }
		os << std::endl;
		return os;
	}
	
	// Сложение 
	// Функции с квалификатором friend не являются функциями-членами класса,
	// хотя и написаны внутри класса -- просто для удобства
	friend Data add(const Data& a, const Data& b) {
		std::cout << "In function add (begin)" << std::endl;
		size_t size = a._size;
		if (size != b._size) { throw std::runtime_error("Different sizes"); }
		Data answer(size);
		for (size_t i = 0; i < size; i++) {
			answer.data[i] = a.data[i] + b.data[i];
		}
		std::cout << "In function add: answer just before return: " << answer;
		return answer;
	}
	
	
private:
	size_t _size = 0;
	int* data = nullptr;
	
};


int main() {
	// Конструкция через лист инициализации
	Data a = {3, 3, 3};
	std::cout << "a: " << a;
	std::cout << "---------------------------" << std::endl;
	
	Data c = {2, 2};
	std::cout << "c: " << c;
	std::cout << "---------------------------" << std::endl;
	
	// Конструкция через копирование (объект a не изменится)
	Data b = a;
	std::cout << "b: " << b;
	std::cout << "---------------------------" << std::endl;
	
	// Копирующий оператор= (объект b не изменится, старые данные объекта c освободятся)
	c = b;
	std::cout << "c: " << c;
	std::cout << "b: " << b;
	std::cout << "---------------------------" << std::endl;
	
	// Функция сложения возвращает временный объект
	Data bc = add(b, c);
	std::cout << "bc: " << bc;
	std::cout << "---------------------------" << std::endl;
	
	return 0;
}

