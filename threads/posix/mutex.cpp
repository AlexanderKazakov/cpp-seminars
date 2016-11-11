#include <iostream>
#include <pthread.h>


struct ThreadHelper {
	/// Мьютекс -- от слова MUTual EXclusion, взаимное исключение --
	/// позволяет разграничить по времени доступ разных потоков
	/// к их общему ресурсу
	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	int counter = 0;
};

void* mutexDemo(void* arg) {
	ThreadHelper* helper = (ThreadHelper*)(arg);
	/// Если мьютекс уже заблокирован, поток будет остановлен, пока
	/// кто-то другой не разблокирует мьютекс.
	/// Когда мьютекс не заблокирован, он будет заблокирован этим потоком
	pthread_mutex_lock(&(helper->mutex));
	std::cout << "Thread number " << pthread_self() 
			<< " are in critical section. ";
	helper->counter++;
	std::cout << "counter == " << helper->counter << std::endl;
	/// Разблокировать мьютекс
	pthread_mutex_unlock(&(helper->mutex));
	return NULL;
}

int main() {
	const size_t N = 5;
	pthread_t threadIds[N];
	ThreadHelper th;
	
	for (int i = 0; i < N; i++) {
		pthread_create(&(threadIds[i]), NULL, mutexDemo, (void*)(&th));
	}
	
	/// Перед возвратом из main необходимо дождаться завершения всех потоков
	for (int i = 0; i < N; i++) {
		pthread_join(threadIds[i], NULL); 
	}
	
	/// Порядок, в котором вызывались потоки, не обязан совпадать
	/// с их реальным порядком исполнения
	for (int i = 0; i < N; i++) {
		std::cout << threadIds[i] << std::endl;
	}
	
	return 0;
}

