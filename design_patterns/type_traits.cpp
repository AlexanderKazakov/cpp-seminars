#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename Iter>
size_t iter_distance_impl(Iter b, Iter e, random_access_iterator_tag) {
    cout << "Implementation for random access iterators" << endl;
    return e - b;
}
template<typename Iter>
size_t iter_distance_impl(Iter b, Iter e, bidirectional_iterator_tag) {
    cout << "Implementation for bidirectional iterators" << endl;
    size_t n = 0;
    while (b++ != e) {++n;}
    return n;
}

template<typename Iter>
size_t iter_distance(Iter begin, Iter end) {
    // Выбор вызываемого алгоритма происходит во время компиляции
    // на основании свойств конкретного шаблонного параметра.
    // Свойства могут быть заданы в том числе извне с помощью
    // вспомогательного класса "type_traits" -- там просто
    // делается частичная специализация для интересующих нас типов
    return iter_distance_impl(begin, end,
        typename iterator_traits<Iter>::iterator_category());
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    cout << iter_distance(v.begin(), v.end()) << endl;
    list<int> l = {7, 7, 7};
    cout << iter_distance(l.begin(), l.end()) << endl;
    return 0;
}
