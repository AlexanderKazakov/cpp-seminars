#include <stdio.h>
#include <stdexcept>
#include <vector>
#include <iostream>


/** Класс-обёртка вокруг файла */
class File {
public:
	File(const char* filename) {
		std::cout << "In plain constructor" << std::endl;
		if ( !(handle = fopen(filename, "w")) ) {
			throw std::runtime_error("Cannot open or create file");
		}
	}
	
	File(const File&) = delete; // запретить копирование
	void operator=(const File&) = delete; // запретить присваивание
	
	~File() {
		std::cout << "In ~File() with handle == " << getHandle() << std::endl;
		if (handle) {
			fclose(handle);
		}
	}
	
	File(File&& that) {
		std::cout << "In move constructor" << std::endl;
		handle = that.handle;
		that.handle = nullptr;
	}
	
	File& operator=(File&& that) {
		std::cout << "In move assignment operator" << std::endl;
		std::swap(handle, that.handle);
		return *this;
	}
	
	FILE* getHandle() { return handle; }
	
private:
	FILE* handle;
};


int main() {
	// C семантикой перемещения это работает
	std::vector<File> files;
	files.push_back(File("data.txt"));
	std::cout << "files[0].getHandle() == " << files[0].getHandle() << std::endl;
	
	std::cout << "-------------------------" << std::endl;
	
	// Здесь компилятор автоматически переделал присваивание в конструктор
	File file = File("data2.txt");
	std::cout << "file.getHandle() == " << file.getHandle() << std::endl;
	
	std::cout << "-------------------------" << std::endl;
	
	// Здесь мы "украли" у file его handle 
	// (file теперь находится в разрушенном состоянии).
	// Заметьте: здесь тоже был вызван конструктор, а не оператор=
	File file2 = std::move(file);
	std::cout << "file.getHandle() == " << file.getHandle() << std::endl;
	std::cout << "file2.getHandle() == " << file2.getHandle() << std::endl;
	
	// std::move принудительно делает из своего аргумента rvalue-ссылку
	// Строка ниже не скомпилируется: use of deleted function File::File(const File&)
//	File file2 = file;
	
	std::cout << "-------------------------" << std::endl;
	
	// А вот здесь уже будет вызван оператор=
	files[0] = std::move(file2);
	std::cout << "files[0].getHandle() == " << files[0].getHandle() << std::endl;
	std::cout << "file2.getHandle() == " << file2.getHandle() << std::endl;
	
	return 0;
}



