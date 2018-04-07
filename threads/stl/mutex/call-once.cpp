#include <iostream>
#include <thread>
#include <mutex>
#include <cassert>

using namespace std;


int main() {
    bool status = false;
    once_flag onceFlag;
    
    auto f = [&](bool toThrow) {
        if (toThrow) { throw "error"; }
        status = true;
    };
    
    auto g = [&](bool toThrow, int n) {
        cout << "Thread " << n << ":" << endl;
        try {
            call_once(onceFlag, f, toThrow);
        } catch (const char*) {
            return;
        }
        assert(status);
    };
    
    // there is a bug in call_once in linux environment (2018 March)
    // if t1 runs first, the program hangs up
    thread t1(g, true, 1);
    thread t2(g, false, 2);
    thread t3(g, false, 3);
    
    t1.join();
    t2.join();
    t3.join();
    return 0;
}

