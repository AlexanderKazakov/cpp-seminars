#include <stdio.h>
#include <stdexcept>
#include <vector>


/** Класс-обёртка вокруг файла */
class File {
public:
	
	File(const char* filename) {
		if ( !(handle = fopen(filename, "r")) ) {
			throw std::runtime_error("blah blah blah");
		}
	}
	
	~File() {
		if (handle) {
			fclose(handle);
		}
	}
	
	
private:
	FILE* handle;
	
	File(const File&); // запретить копирование объекта
	void operator=(const File&); // запретить присваивание объекта
};


int main() {
	// Это не скомпилируется
//	std::vector<File> files;
//	files.push_back(File("data.txt"));
	
	// Выход из ситуации без семантики перемещения
	std::vector<File*> files;
	files.push_back(new File("data.txt"));
	
	
}
