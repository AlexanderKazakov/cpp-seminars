#include <iostream>

// Работа по C++03 отличается от C++11

struct Finalizer {
    Finalizer(std::string const& str) :_str(str) { }
    ~Finalizer() { std::cout << "~Finalizer: \"" << _str << "\"" << std::endl; }
    const std::string& _str;
};

std::string f() {
    // ломаем оптимизацию компилятора
    if (false) { return std::string("It never happens"); }
    std::string s = "s";
    Finalizer finalizer(s);
    return s;
}

int main() {
    std::string s = f();
    return 0;
}
