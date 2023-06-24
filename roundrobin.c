/*
 * 	Program	-> Round Robin CPU Scheduling Algorithm
 * 	Author 	-> rosettastoned12
 * */

#include<stdio.h>

struct process {
	int pid, bt, rbt, tat, wt;
}p[50], out[50];	// out[] array represents the order of process execution

int main() {
	int i, j, k=1, timeQuanta, numberOfProcesses, netBurst=0, 
	
	printf("Reading the number of processes... ");
	scanf("%d", &numberOfProcesses);

	printf("Reading the burst time of each process... \n");
	for (i=0; i<numberOfProcesses; i++) {
		printf("Process %d\t->\t", i+1);
		scanf("%d", &p[i].bt);
		//Initializing RBT of each process with their BTs
		p[i].rbt = p[i].bt;
		netBurst += p[i].bt;
	}
	
	//Read the time slice
	printf("\nReading the time slice... ");
	scanf("%d", &timeQuanta);

	//Initialize the TAT of the first process with 0
	out[0].tat = 0;

	int compareTAT = 0;

	while (compareTAT != netBurst) {
		for (i=0; i<numberOfProcesses; i++) {
			if (p[i].rbt != 0) {
				out[k].pid = i+1;
				
				// Execute if the RBT-QT of the process is less than or equal to 0
				if (p[i].rbt - qt <= 0) {
					out[k].wt = out[k-1].tat; // WT of current is TAT of previous
					out[k].bt = p[i].rbt;
					out[k].tat = out[k].wt + out[k].bt // TAT = WT + BT

					//set RBT of process to 0


				}
			}
		}
	}

	return 0;
}
