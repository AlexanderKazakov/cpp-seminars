#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 3, 4, 5};
    list<int> l = {4, 3, 2};
    
    cout << count(v.begin(), v.end(), 3) << endl;
    cout << count_if(v.begin(), v.end(), [](int i){return i%2;}) << endl;
    cout << *max_element(v.begin(), v.end()) << endl;
    cout << (find(v.begin(), v.end(), 7) == v.end()) << endl;
    cout << *find_if_not(v.begin(), v.end(), [](int i){return i%2;}) << endl;
    cout << *find_first_of(v.begin(), v.end(), l.begin(), l.end()) << endl;
    
    cout << equal(l.begin(), l.end(), v.begin()) << endl;
    copy(l.begin(), l.end(), v.begin());
    for (int i : l) {cout << i << " ";} cout << endl;
    for (int i : v) {cout << i << " ";} cout << endl;
    cout << equal(l.begin(), l.end(), v.begin()) << endl;
    cout << binary_search(v.begin(), v.end(), 3) << endl;
    
    reverse(l.begin(), l.end());
    rotate(l.begin(), next(l.begin()), l.end());
    for (int i : l) {cout << i << " ";} cout << endl;
    
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    transform(v.begin(), v.end(), v.begin(), [](int i){return 2*i;});
    for (int i : v) {cout << i << " ";} cout << endl;
    
    cout << all_of(v.begin(), v.end(), [](int i){return i%2 == 0;}) << endl;
    cout << any_of(l.begin(), l.end(), [](int i){return i > 5;}) << endl;
    
    cout << *lower_bound(v.begin(), v.end(), 6) << endl;
    cout << *upper_bound(v.begin(), v.end(), 6) << endl;
    
    /// ... (http://en.cppreference.com/w/cpp/algorithm)
    return 0;
}
