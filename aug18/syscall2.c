#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void main() {
	int pid = fork();
	if (pid == 0) {
		execlp("/bin/date","date", NULL);
		exit(0);
	} else if (pid < 0) {
		printf("Error\n");
		exit(1);
	} else {
		printf("PID of parent : %d\n", getpid());
		wait(NULL);
		exit(0);
	}
}
