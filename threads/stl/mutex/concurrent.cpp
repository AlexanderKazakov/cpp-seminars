#include <iostream>
#include <thread>
#include <cstring>
#include <numeric>

using namespace std;


int main() {
    const int N = 1000000;
    int arr[N];
    memset(arr, 0, N * sizeof(int));
    
    thread t1([&](){ for (int &i : arr) { i = 1; } });
    thread t2([&](){ for (int &i : arr) { i = 2; } });

    t1.join();
    t2.join();
    cout << accumulate(arr, arr + N, 0);
    
    return 0;
}

