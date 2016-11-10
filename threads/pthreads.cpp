#include <iostream>
#include <pthread.h>


/// Compile like " g++ -pthread "


void* f(void* threadId) {
	std::cout << (size_t)threadId << std::endl;
	pthread_exit(NULL);
}


int main() {
	const size_t threadsNum = 10;
	for (size_t i = 0; i < threadsNum; i++) {
		pthread_t thread;
		if (pthread_create(&thread, NULL, f, (void *)i)) {
			std::cerr << "Failed to create "
					<< i << "'th thread" << std::endl;
			pthread_exit(NULL);
			return -1;
		}
	}
	pthread_exit(NULL);
	return 0;
}

