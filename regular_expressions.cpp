#include <iostream>
#include <regex>

/// Исчерпывающая информация по регулярным выражениям в C++11:
/// http://www.cplusplus.com/reference/regex/ECMAScript/

using namespace std;

int main() {
    string s = "One \"two\" three";
    // \w    -- буква, цифра или знак подчёркивания
    // \w+   -- одна или больше буква, цифра или знак подчёркивания
    // (...) -- "capturing group" -- то, что ищем
    string pattern = "(\\w+) \"(\\w+)\" (\\w+)";
    smatch match;
    if (regex_match(s, match, regex(pattern))) {
        for (auto m : match) { cout << m << endl; }
    }
    /// Это та же самая строка, что и выше:
    /// R -- "raw string" -- то есть все символы воспринимаются компилятором
    /// как есть, в том числе слеши и ковычки
    pattern = R"###((\w+) "(\w+)" (\w+))###";
    
    cout << "==========================" << endl;
    
    s = "<lala>123</lala>";
    // \d -- цифра
    // \1 -- ссылка на предыдущую capturing group
    pattern = R"###(<(\w+)>(\d+)</\1>)###";
    if (regex_match(s, match, regex(pattern))) {
        cout << match[1] << ": " << match[2] << endl;
    }
    
    cout << "==========================" << endl;
    
    // \s      -- пробел
    // .       -- любой символ, кроме переноса строки
    // \d{3,5} -- от 3 до 5 цифр
    // x*      -- от 0 до бесконечности символа 'x'
    s = "lalala  : 234 jfi*jfe  fefo";
    pattern = R"###(lalala\s+:\s+(\d{3,5}).*)###";
    if (regex_match(s, match, regex(pattern))) {
        cout << match[1] << endl;
    }
    
    return 0;
}
