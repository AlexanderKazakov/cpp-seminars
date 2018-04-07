#include <mutex>
#include <thread>
#include <iostream>


struct Box {
    explicit Box(int num) : num_things{num} {}
    int num_things;
    std::mutex m;
};

void transfer(Box &from, Box &to, int num) {
    std::lock_guard<std::mutex> lock1(from.m);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> lock2(to.m);
    
    from.num_things -= num;
    to.num_things += num;
}

int main() {
    Box acc1(100), acc2(50);
    std::cout << acc1.num_things << ":" << acc2.num_things << std::endl;
    
    std::thread t1(transfer, std::ref(acc1), std::ref(acc2), 10);
    std::thread t2(transfer, std::ref(acc2), std::ref(acc1), 5);
    t1.join();
    t2.join();
    std::cout << acc1.num_things << ":" << acc2.num_things << std::endl;
}
