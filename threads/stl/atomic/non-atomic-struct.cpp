#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

using namespace std;


struct S {
    S(int a, int b) : a(a), b(b) { }
    void increment(int val) {
        a = a + val;
        b = b + val;
    }
    int a, b;
};

S s(0, 0);

void foo(int val) {
    s.increment(val);
}

int main() {
    vector<thread> threads;
    for (int i = 0; i < 1000; ++i) {
        threads.emplace_back(foo, 1);
    }
    for (thread& t : threads) {
        t.join();
    }
    cout << s.a << " " << s.b << endl;
    return 0;
}

