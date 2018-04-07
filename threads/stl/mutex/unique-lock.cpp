#include <mutex>
#include <thread>
#include <iostream>

// from cppreference.com

// unique_lock -- более функциональная версия lock_guard, позволяет:
// - Принимать не захваченный мьютекс в конструкторе
// - Захватывать и освобождать мьютекс непосредственными вызовами lock/unlock
// - Выполнять временный захват
// - Может быть перемещен в другой объект unique_lock

struct Box {
    explicit Box(int num) : num_things{num} {}
    int num_things;
    std::mutex m;
};

void transfer(Box &from, Box &to, int num) {
    // don't actually take the locks yet
    std::unique_lock<std::mutex> lock1(from.m, std::defer_lock);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::unique_lock<std::mutex> lock2(to.m, std::defer_lock);
    
    // lock both unique_locks without deadlock
    std::lock(lock1, lock2);
    
    from.num_things -= num;
    to.num_things += num;
    // 'from.m' and 'to.m' mutexes unlocked in 'unique_lock' dtors
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
