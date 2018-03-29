#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;


int main() {
    mutex m;
    condition_variable cv;
    bool b = false;
    
    thread t1([&]() {
        {
            unique_lock<mutex> lock(m);
//            this_thread::sleep_for(chrono::milliseconds(500));
            b = true;
            cout << "1 " << boolalpha << b << endl;
        }
        cv.notify_one();
        
        {
            unique_lock<mutex> lock(m);
//            this_thread::sleep_for(chrono::milliseconds(500));
            cv.wait(lock, [&]{return !b;});
            b = true;
            cout << "3 " << b << endl;
        }
        cv.notify_one();
    });
    
    thread t2([&]() {
        {
            unique_lock<mutex> lock(m);
//            this_thread::sleep_for(chrono::milliseconds(500));
            cv.wait(lock, [&]{return b;});
            b = false;
            cout << "2 " << b << endl;
        }
        cv.notify_one();
    
        {
            unique_lock<mutex> lock(m);
//            this_thread::sleep_for(chrono::milliseconds(500));
            cv.wait(lock, [&]{return b;});
            b = false;
            cout << "4 " << b << endl;
        }
    });
    
    t1.join();
    t2.join();
    return 0;
}

