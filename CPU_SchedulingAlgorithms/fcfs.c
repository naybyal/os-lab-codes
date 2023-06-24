/*
 *	Program	-> FIRST COME FIRST SERVE CPU SCHEDULING ALGORITHM
 *	Author	-> rosettastoned12
 * */

#include<stdio.h>

struct process {
	//	TAT - Turn Around Time 
	//	WT  - Waiting Time
	//	BT  - Burst Time
	int tat,wt,bt,id;
}p[50],temp;

int main() {
	int i,j,numberOfProcesses;

 	//To calculate averageTAT and averageWT
	int total_TAT=0, total_WT=0;

	printf("Reading the number of processes... ");
	scanf("%d", &numberOfProcesses);

	//Set the waiting time of the first process to 0
	p[0].wt = 0;

	printf("Reading the burst times (in ms) of each process...\n");
	for (i=0; i<numberOfProcesses; i++) {
		printf("Process %d\t->\t", i+1);
		scanf("%d", &p[i].bt);
		p[i].id = i+1; //setting the id, starting from 1
	}

	/*
	 * Waiting Time of each process will be
	 * the sum of Burst Time and Waiting Time
	 * of the previous process
	 */

	for (i=1; i<numberOfProcesses; i++) {
		p[i].wt = p[i-1].bt + p[i-1].wt;
		total_WT += p[i].wt;
	}

	/*
	 * Turn Around Time of current process will be
	 * the sum of Waiting Time and Burst Time of the current process
	 */

	for (i=0; i<numberOfProcesses; i++) {
		p[i].tat = p[i].bt + p[i].wt;
		total_TAT += p[i].tat;
	}

	// Displaying the process, BT, WT and TAT as a table
	printf("\nPROCESS\tBT\tWT\tTAT");
	for (i=0; i<numberOfProcesses; i++) {
		printf("\nP%d\t%d\t%d\t%d", p[i].id, p[i].bt, p[i].wt, p[i].tat);
	}
	printf("\n");
	
	// Average Time = Total Time / Number of Processes
	float avg_TAT = (float)total_TAT / numberOfProcesses;
	float avg_WT = (float)total_WT / numberOfProcesses;
	printf("\nAverage TAT\t->\t%.1fms", avg_TAT);
	printf("\nAverage WT \t->\t%.1fms", avg_WT);
	printf("\n\n");
	
	//Displaying GANTT Chart
	printf("----GANTT Chart----\n");
	for (i=0; i<numberOfProcesses; i++) 
		printf("| \tP%d \t", p[i].id);
	printf("|\n");
	printf("0\t");
	for (i=0; i<numberOfProcesses; i++) 
		printf("\t%d\t", p[i].tat);
	printf("\n");

	printf("\n---LEGEND---\nBT  -> Burst Time\nWT  -> Waiting Time\nTAT -> Turn Around Time");
	printf("\n------------\n");
	return 0;

}
