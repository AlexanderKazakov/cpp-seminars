#include <iostream>
#include <thread>
#include <condition_variable>

using namespace std;


const int N = 5;

mutex m[N];
condition_variable cv[N];
bool b[N];


void doTheJob(int n, int mis) {
    while (true) {
        cout << "Thread " << n << " doing job ..." << endl;
        this_thread::sleep_for(chrono::milliseconds(mis));
        cout << "Thread " << n << " job done!" << endl;
        
        {
            lock_guard<mutex> lock(m[n]);
            b[n] = true;
        }
        cv[n].notify_one();
        
        {
            unique_lock<mutex> lock(m[n]);
            if (b[n]) {
                cv[n].wait(lock, [n]() { return !b[n]; });
            }
        }
    }
}

int main() {
    for (bool& b1 : b) { b1 = false; }
    
    cout << "Starting threads ..." << endl;
    for (int i = 0; i < N; i++) {
        thread(doTheJob, i, i * 500).detach();
    }
    
    while (true) {
        for (int i = 0; i < N; i++) {
            unique_lock<mutex> lock(m[i]);
            if (!b[i]) {
                cv[i].wait(lock, [i]() { return b[i]; });
            }
        }
        cout << "All threads reached the barrier!" << endl;
        for (int i = 0; i < N; i++) {
            {
                unique_lock<mutex> lock(m[i]);
                b[i] = false;
            }
            cv[i].notify_one();
        }
    }
}

