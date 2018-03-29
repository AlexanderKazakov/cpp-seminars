#include <iostream>
#include <thread>
#include <mutex>

using namespace std;


struct S {
    int get_a() const {
        lock_guard<recursive_mutex> lg(m);
        int ans = _a;
        return ans;
    }
    void set_a(int a) {
        lock_guard<recursive_mutex> lg(m);
        _a = a;
    }
    int get_b() const {
        lock_guard<recursive_mutex> lg(m);
        int ans = _b;
        return ans;
    }
    void set_b(int b) {
        lock_guard<recursive_mutex> lg(m);
        _b = b;
    }
    void set_a_b(int a, int b) {
        lock_guard<recursive_mutex> lg(m);
        set_a(a);
        this_thread::sleep_for(chrono::milliseconds(100));
        set_b(b);
    }
    int sum() const {
        lock_guard<recursive_mutex> lg(m);
        int a = get_a();
        this_thread::sleep_for(chrono::milliseconds(100));
        return a + get_b();
    }
private:
    int _a = 0, _b = 0;
    mutable recursive_mutex m;
};

int main() {
    S s;
    thread t1([&](){
        s.set_a_b(1, 1);
    });
    thread t2([&](){
        cout << s.sum() << endl;
    });
    
    t1.join();
    t2.join();
    return 0;
}

