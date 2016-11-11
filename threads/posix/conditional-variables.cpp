#include <iostream>
#include <pthread.h>

#define COUNT_MAX 10
#define COUNT_ONE  3
#define COUNT_TWO  7

struct ThreadHelper {
	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t conditionVar = PTHREAD_COND_INITIALIZER;
	int counter = 0;
};

void* f(void* arg) {
	ThreadHelper* th = (ThreadHelper*)(arg);
	while (th->counter < COUNT_MAX) {
		pthread_mutex_lock(&(th->mutex));
		/// Вызов pthread_cond_wait автоматически разблокирует мьютекс,
		/// а когда сигнал придёт, автоматически заблокирует его обратно
		pthread_cond_wait(&(th->conditionVar), &(th->mutex));
		std::cout << "f: counter == " << ++(th->counter) << std::endl;
		pthread_mutex_unlock(&(th->mutex));
	}
	return NULL;
}

void* g(void* arg) {
	ThreadHelper* th = (ThreadHelper*)(arg);
	while (th->counter < COUNT_MAX) {
		pthread_mutex_lock(&(th->mutex));
		if (th->counter < COUNT_ONE || COUNT_TWO < th->counter) {
			pthread_cond_signal(&(th->conditionVar));
		} else {
			std::cout << "g: counter == " << ++(th->counter) << std::endl;
		}
		pthread_mutex_unlock(&(th->mutex));
	}
	return NULL;
}

int main() {
	pthread_t tf, tg;
	ThreadHelper threadHelper;
	pthread_create(&tf, NULL, f, &threadHelper);
	pthread_create(&tg, NULL, g, &threadHelper);
	
	pthread_join(tf, NULL);
	pthread_join(tg, NULL);
	return 0;
}

