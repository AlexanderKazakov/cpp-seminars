#include <iostream>
#include <thread>
#include <atomic>

using namespace std;


atomic_flag lock = ATOMIC_FLAG_INIT;

void foo(int n) {
    while (true) {
        while (lock.test_and_set(memory_order_acquire));
        cout << n << n << endl;
        this_thread::sleep_for(chrono::milliseconds(10));
        lock.clear(memory_order_release);
    }
}

int main() {
    for (int i = 0; i < 10; ++i) {
        thread(foo, i).detach();
    }
    this_thread::sleep_for(chrono::milliseconds(100));
    return 0;
}

