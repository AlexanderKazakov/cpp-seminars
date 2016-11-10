#include <iostream>
#include <unistd.h>
#include <wait.h>
#include <cstdlib>
#include <cassert>
#include <string>


int main(int argc, char** argv) {
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;
	assert(argc == 2);
	
	pid_t pid = fork();
	switch (pid) {
	case -1:
		std::cerr << "Error in fork()" << std::endl;
		return -1;
		break;
	case 0:
	{
		std::cout << "I'm child."
				<< "\tMy PID " << getpid()
				<< "\tMy parent PID " << getppid()
				<< std::endl;
		sleep(5);
		int counter = atoi(argv[1]);
		if (counter > 0) {
			execl(argv[0],
				argv[0], std::to_string(counter - 1).c_str(), NULL);
		}
		std::cout << "Counter finished" << std::endl;
		break;
	}
	default:
		std::cout << "I'm parent."
				<< "\tMy PID " << getpid()
				<< "\tMy child PID " << pid
				<< std::endl;
		wait(NULL);
		std::cout << "Exit from parent " << getpid() << std::endl; 
		break;
	}
	
	return 0;
}


