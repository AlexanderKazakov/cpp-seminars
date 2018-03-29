#include <iostream>
#include <thread>

using namespace std;


int main() {
    cout << "start main()" << endl;
    
    // Из потока нельзя бросать исключение
    try {
        thread t1([]() {
            cout << "t1 start" << endl;
            throw "Some exception";
        });
        t1.join();
    } catch (...) {
        cout << "Exception was thrown" << endl;
    }
    
    cout << "end main()" << endl;
    return 0;
}

