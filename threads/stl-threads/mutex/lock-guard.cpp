#include <iostream>
#include <thread>
#include <mutex>
#include <cstring>
#include <numeric>

using namespace std;


int main() {
    const int N = 1000000;
    int arr[N];
    memset(arr, 0, N * sizeof(int));
    
    mutex m;
    thread t1([&](){
        lock_guard<mutex> lg(m);
        for (int &i : arr) { i = 1; }
    });
    thread t2([&](){
        lock_guard<mutex> lg(m);
        for (int &i : arr) { i = 2; }
    });

    t1.join();
    t2.join();
    cout << accumulate(arr, arr + N, 0);
    
    return 0;
}

