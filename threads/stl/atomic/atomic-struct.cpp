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

S initS(0, 0);
std::atomic<S> sGlob(initS);

void foo(int val) {
    S local = sGlob.load();
    local.increment(val);
    sGlob.store(local);
}

int main() {
    vector<thread> threads;
    for (int i = 0; i < 1000; ++i) {
        threads.emplace_back(foo, 1);
    }
    for (thread& t : threads) {
        t.join();
    }
    S local = sGlob.load();
    cout << local.a << " " << local.b << endl;
    return 0;
}

