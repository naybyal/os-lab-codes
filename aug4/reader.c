#include<stdio.h> 
#include<sys/ipc.h> 
#include<sys/shm.h>
void main() {   
	key_t key=ftok("Hello",60);
	int shmid=shmget(key,1024,0666 | IPC_CREAT); 
	char *str=(char*)shmat(shmid,(void*)0,0); 
	
	printf("\n Data read from Shared Memory: "); 
	puts(str);
	shmdt(str); 
    	shmctl(shmid,IPC_RMID,NULL);
}
