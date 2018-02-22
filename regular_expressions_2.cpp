#include <iostream>
#include <regex>

/// Исчерпывающая информация по регулярным выражениям в C++11:
/// http://www.cplusplus.com/reference/regex/ECMAScript/

using namespace std;

int main() {
    string s = "hihvuih990uh   lalala  : 234 jfi*jfe  fefo ghfruiri";
    string pattern = R"###(lalala\s+:\s+(\d{3,5}))###";
    smatch match;
    /// match проверяет полное соответствие всей строки, а
    /// search ищет первое соответствие любой подстроки
    if (regex_search(s, match, regex(pattern))) {
        cout << match[1] << endl;
    }
    
    cout << "==========================" << endl;
    
    cout << s << endl;
    s = regex_replace(s, regex("[a-z]{3}"), "---");
    cout << s << endl;
    s = regex_replace(s, regex("\\s+"), "");
    cout << s << endl;
    
    cout << "==========================" << endl;
    
    s = // так задавать строки тоже можно
            "<!DOCTYPE html>\n"
            "<html>\n"
            "<body>\n"
            "\n"
            "<h1>My First Heading</h1>\n"
            "\n"
            "<p>My first paragraph.</p>\n"
            "\n"
            "</body>\n"
            "</html>";
    pattern = R"###(<\w+>)###";
    regex reg_pattern = regex(pattern);
    for (auto iter = sregex_iterator(s.begin(), s.end(), reg_pattern);
            iter != sregex_iterator(); ++iter) {
        cout << iter->str() << endl;
    }
    
    return 0;
}
