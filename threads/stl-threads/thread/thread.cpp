#include <iostream>
#include <thread>

using namespace std;


void foo(int i) { cout << this_thread::get_id() << " foo(), i == " << i << endl; }

struct Bar { void operator()() { cout << this_thread::get_id() << " Bar::operator()" << endl; } };

int main() {
    cout << this_thread::get_id() << " start main()" << endl;
    
    thread t2(foo, 7);
    t2.join();
    
    Bar bar;
    thread t3(bar);
    t3.join();
    
    thread t4([](){
        cout << this_thread::get_id() << " lambda-function" << endl;
    });
    t4.join();
    
    cout << this_thread::get_id() << " end main()" << endl;
    return 0;
}

