/*
 * 	Program	-> Round Robin CPU Scheduling Algorithm
 * 	Author 	-> rosettastoned12
 * */

#include<stdio.h>

struct process {
	int id, bt, rbt, tat, wt;
}p[50], out[50];	// out[] array represents the order of process execution

int main() {
	int i, j, k=1, timeQuanta, numberOfProcesses, netBurst=0; 
	int totalTAT=0, totalWT=0;

	printf("Reading the number of processes... ");
	scanf("%d", &numberOfProcesses);

	printf("Reading the burst time of each process... \n");
	for (i=0; i<numberOfProcesses; i++) {
		p[i].id = i+1;
		printf("Process %d\t->\t", i+1);
		scanf("%d", &p[i].bt);
		// Initializing RBT of each process with their BTs
		p[i].rbt = p[i].bt;
		netBurst += p[i].bt;
	}
	
	// Read the time slice
	printf("\nReading the time slice... ");
	scanf("%d", &timeQuanta);

	// Initialize the TAT of the first process with 0
	out[0].tat = 0;

	int compareTAT = 0;

	while (compareTAT != netBurst) {
		for (i=0; i<numberOfProcesses; i++) {
			if (p[i].rbt != 0) {
				out[k].id = i+1;
				
				// Execute if the RBT-timeQuanta of the process is less than or equal to 0
				if (p[i].rbt - timeQuanta <= 0) {
					out[k].wt = out[k-1].tat; // WT of current is TAT of previous
					out[k].bt = p[i].rbt;
					out[k].tat = out[k].wt + out[k].bt; // TAT = WT + BT

					// Set RBT of process to 0
					p[i].rbt = 0;

					// Update TAT of the process
					p[i].tat = out[k].tat;
					
					// Update WT of the process
					p[i].wt = p[i].tat - p[i].bt;

					// Set compareTAT to the TAT of kth process and increment k
					compareTAT = out[k].tat;
					k++;	
					
					// Update totalTAT and totalWT
					totalTAT += p[i].tat;
					totalWT += p[i].wt;	
				} else {
					// If the remaining burst time is greater than 0

					out[k].wt = out[k-1].tat;	// WT of kth process is the TAT of the previous
					
					// TAT of kth process will be sum of WT and timeQuanta
					out[k].tat = out[k].wt + timeQuanta;

					// Decrement timeQuanta from the RBT of each process
					p[i].rbt -= timeQuanta;

					// Set compareTAT to the TAT of the kth process and increment k
					compareTAT = out[k].tat;
					k++;
				}
			}
		}
	}

	printf("\nPROCESS\tWT\tTAT\tBT\n");
	for (i=0; i<numberOfProcesses; i++)
		printf("%d\t%d\t%d\t%d\n", p[i].id, p[i].wt, p[i].tat, p[i].bt);
	printf("\n");

	float avgTAT = (float)totalTAT/numberOfProcesses;
	float avgWT = (float)totalWT/numberOfProcesses;

	printf("\nAverage TAT\t->\t%.1f", avgTAT);
	printf("\nAverage WT\t->\t%.1f\n", avgWT);

	// Displaying the GANTT chart
	printf("\n---GANTT CHART---\n");
	for (i=1; i<k; i++) 
		printf("|\tP%d\t",out[i].id);
	printf("|\n");
	for (i=0; i<k; i++) 
		printf("%d\t\t", out[i].tat);
	printf("\n");		
	return 0;
}
