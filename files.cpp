#include <iostream>
#include <iomanip> // форматирование ввода-вывода
#include <fstream> // чтение или запись в файл
/// или ifstream -- для чтения
/// или ofstream -- для записи

using namespace std;

inline void check(bool, string);

int main() {
    fstream fs("fileToRead.txt", ios_base::in);
    check(fs.is_open(), "Не могу открыть файл на чтение");
    for (string str; getline(fs, str);) {
        cout << str << endl;
    }
    /// Также можно читать/писать посимвольно через .get()/.put()
    /// Либо через операторы >> и <<
    check(!fs.bad(), "Какие-то ошибки при работе с файлом");
    check(fs.eof(), "Должен был быть достигнут конец файла");
    check(!fs.good(), "Невозможно, если до сюда дошли"); // good() это не !bad(), см. документацию
    fs.close();
    
    fs.open("fileToWrite.txt", ios_base::out | ios_base::app);
    check(fs.is_open(), "Не могу открыть файл на запись");
    for (int i = 0; i < 7; i++) {
        fs << setprecision(i) << fixed << 12.345 << endl;
    }
    for (int i = 0; i < 7; i++) {
        fs << setprecision(i) << scientific << 12.345 << endl;
    }
    /// Для более тонкого форматирования используется сишный fprintf
    
    fs.close();
    /// в данном случае .close() в принципе не обязательна:
    /// во-первых, она автоматически вызывается деструктором
    /// во-вторых, при любом завершении процесса система сама разберётся
    return 0;
}

inline void check(bool cond, string errMsg) {
    if (!cond) {
        cerr << errMsg << endl;
        exit(EXIT_FAILURE);
    }
}
