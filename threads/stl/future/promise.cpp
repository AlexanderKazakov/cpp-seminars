#include <iostream>
#include <thread>
#include <future>
#include <vector>

using namespace std;


void doTheJob(int n, int ms, promise<void> finishSignal) {
    cout << "Thread " << n << " doing job ..." << endl;
    this_thread::sleep_for(chrono::milliseconds(ms));
    cout << "Thread " << n << " finished!" << endl;
    finishSignal.set_value();
}

int main() {
    cout << "Starting threads ..." << endl;
    vector<future<void>> futures;
    for (int i = 0; i < 10; i++) {
        promise<void> p;
        futures.push_back(move(p.get_future()));
        thread(doTheJob, i, i * 100, move(p)).detach();
    }
    for (const future<void>& f : futures) {
        f.wait();
    }
    cout << "All threads finished!" << endl;
    return 0;
}

