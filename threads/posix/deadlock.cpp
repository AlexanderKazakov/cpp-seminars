#include <iostream>
#include <pthread.h>

struct ThreadHelper {
	pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
	pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
};

void* f(void* arg) {
	ThreadHelper* th = (ThreadHelper*)(arg);
	pthread_mutex_lock(&(th->mutex1));
	pthread_mutex_lock(&(th->mutex2));
	// .....
	pthread_mutex_unlock(&(th->mutex2));
	pthread_mutex_unlock(&(th->mutex1));
	return NULL;
}

void* g(void* arg) {
	ThreadHelper* th = (ThreadHelper*)(arg);
	pthread_mutex_lock(&(th->mutex2));
	pthread_mutex_lock(&(th->mutex1));
	// .....
	pthread_mutex_unlock(&(th->mutex1));
	pthread_mutex_unlock(&(th->mutex2));
	return NULL;
}

int main() {
	pthread_t tf, tg;
	ThreadHelper threadHelper;
	/// В ходе работы возможна ситуация, когда f заблокирует первый мьютекс,
	/// а g -- второй, после чего они будут бесконечно ждать друг друга.
	/// Такие ситуации называются "deadlock"
	for (int i = 0; i < 1000000; i++) {
		if (i % 10000 == 0) { std::cout << "i == " << i << std::endl; }
		pthread_create(&tf, NULL, f, &threadHelper);
		pthread_create(&tg, NULL, g, &threadHelper);
		pthread_join(tf, NULL);
		pthread_join(tg, NULL);
	}
	return 0;
}

