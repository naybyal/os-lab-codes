#include<stdio.h>

struct process {
	int bt, id, tat, wt;
}p[50], temp;

void main() {
	int n, i, j, totalTAT=0, totalWT=0;
	float avgTAT, avgWT;

	//	Read the number of processes.
	printf("Reading the number of processes... ");
	scanf("%d", &n);

	//	Set the waiting time of the first process as 0
	p[0].wt = 0;

	//	Read the burst times of each processes
	printf("Reading burst times...\n");
	for (i=0; i<n; i++) {
		printf("Process %d\t->\t", i+1);
		scanf("%d", &p[i].bt);
		//	Set the IDs along the way...
		p[i].id = i+1;
	}

	//	Before calculations sort all the processes based on their burst times...
	for (i=0; i<n; i++) {
		for (j=0; j<n-i-1; j++) {
			if(p[j].bt > p[j+1].bt) {
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}

	//	Calculate WT for 2nd process onwards as (BT+WT) of the previous process
	for (i=1; i<n; i++) {
		p[i].wt = p[i-1].bt + p[i-1].wt;
		totalWT += p[i].wt;
	}
	
	//	TAT = WT + BT
	for (i=0;i<n;i++) {
		p[i].tat = p[i].bt + p[i].wt;
		totalTAT += p[i].tat;
	}

	
	printf("\n\nPROCESS\tBT\tWT\tTAT");
	for (i=0; i<n; i++)
		printf("\nP%d\t%d\t%d\t%d",p[i].id, p[i].bt, p[i].wt, p[i].tat);
	printf("\n\n");
	avgTAT = (float)totalTAT/n;
	avgWT = (float)totalWT/n;

	printf("Total WT\t->-\t%.1f ms", avgWT);
	printf("\nTotal TAT\t->\t%.1f ms", avgTAT);

	printf("\n\n~~~~~~GANTT CHART~~~~~~\n");
	for (i=0; i<n; i++)
		printf("| \tP%d\t ", p[i].id);
	printf("|\n");

	printf("0\t");
	for(i=0; i<n; i++)
		printf("\t %d\t", p[i].tat);
	printf("\n");
}
