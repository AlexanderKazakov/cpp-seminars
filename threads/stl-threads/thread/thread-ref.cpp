#include <iostream>
#include <thread>

using namespace std;


int main() {
    int i = 0;
    cout << i << endl;
    
    thread t1([&](){ ++i; });
    t1.join();
    cout << i << endl;
    
    // thread t2([](int& j){ ++j; }, i); -- compilation error
    thread t2([](int& j){ ++j; }, std::ref(i));
    t2.join();
    cout << i << endl;
    
    return 0;
}

