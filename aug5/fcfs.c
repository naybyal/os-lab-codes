#include<stdio.h>

struct process {
	int id, bt, tat, wt;
}p[50];

void main() {
	int i,j,n;

	int totalTAT=0, totalWT=0;
	float avgTAT, avgWT;

	//	Read the number of preocesses...
	printf("Reading the number of processes... ");
	scanf("%d", &n);

	//	setting the waiting time of initial process to 0
	p[0].wt = 0;

	//	Reading the burst times of each processes.
	printf("Reading the burst times of each processes...\n");
	for (i=0; i<n; i++) {
		printf("Process %d\t->\t", i+1);
		scanf("%d", &p[i].bt);
		//	Setting the process IDs; starting from 1
		p[i].id = i+1;
	}

	//	WT = (BT + WT) of previous process
	for (i=1; i<n; i++) {
		p[i].wt = p[i-1].bt + p[i-1].wt;
		totalWT += p[i].wt;	//	no need to consider the first process as its wt=0
	}

	for (i=0;i<n;i++) {
		p[i].tat = p[i].bt + p[i].wt;
		totalTAT += p[i].tat;
	}

	//	Displaying the table..
	printf("\nPROCESS\tBT\tWT\tTAT");
	for (i=0; i<n; i++)
		printf("\n%d\t%d\t%d\t%d",p[i].id, p[i].bt, p[i].wt, p[i].tat);
	
	//	Display the average WT and TAT
	avgTAT = (float)totalTAT/n;
	avgWT = (float)totalWT/n;
	printf("\n\nTotal TAT\t->\t%.1f ms", avgTAT);
	printf("\nTotal WT\t->\t%.1f ms", avgWT);

	//	Dispalying the GANTT chart...
	printf("\n\n~~~~~~GANTT CHART~~~~~~\n\n");
	for (i=0; i<n; i++)
		printf("| \tP%d \t", p[i].id);
	printf("|\n");
	printf("0\t");
	for (i=0; i<n; i++)
		printf("\t%d\t", p[i].tat);
	printf("\n");
}
