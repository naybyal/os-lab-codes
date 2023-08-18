#include<stdio.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<sys/ipc.h>
void main() {
	key_t key = ftok("Hello", 60);
	int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
	char *str = (char*)shmat(shmid, (void*)0, 0);

	printf("Reading from shared memory....\n");
	puts(str);
	shmdt(str);
	shmctl(shmid, IPC_RMID, NULL);
}
