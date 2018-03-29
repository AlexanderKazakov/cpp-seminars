#include <iostream>
#include <thread>

using namespace std;


int main() {
    cout << "start main()" << endl;
    
    thread t1([]() {
        cout << "t1 start" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "t1 end" << endl;
    });
    this_thread::sleep_for(chrono::milliseconds(500));
//    t1.join();
//    t1.detach();
    
    cout << "end main()" << endl;
    return 0;
}

