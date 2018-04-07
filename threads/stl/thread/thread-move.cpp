#include <iostream>
#include <thread>

using namespace std;


int main() {
    thread t1([]() {
        cout << "t1 start" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "t1 end" << endl;
    });
    
    thread t2([](thread t) {
        cout << "t2 start" << endl;
        t.join();
        cout << "t2 end" << endl;
    }, move(t1));
    t2.join();
    
    return 0;
}

