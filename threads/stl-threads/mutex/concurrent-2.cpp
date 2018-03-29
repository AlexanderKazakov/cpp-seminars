#include <iostream>
#include <thread>

using namespace std;


struct S {
    int get_a() const {
        return _a;
    }
    void set_a(int a) {
        _a = a;
    }
    int get_b() const {
        return _b;
    }
    void set_b(int b) {
        _b = b;
    }
    void set_a_b(int a, int b) {
        set_a(a);
        this_thread::sleep_for(chrono::milliseconds(100));
        set_b(b);
    }
    int sum() const {
        int a = get_a();
        this_thread::sleep_for(chrono::milliseconds(100));
        return a + get_b();
    }
private:
    int _a = 0, _b = 0;
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

