#include<stdio.h>

int n,i;

struct process{
	int id, bt, tat, wt;
}p[50];

void main() {
	printf("\n---FCFS CPU SCHEDULING---\n\n");
	printf("Reading the number of processes... ");
	scanf("%d", &n);

	//	Reading the burst times of each process... 
	printf("Reading the burst times... \n");
	for (i=0;i<n;i++) {
		p[i].id = i+1;
		printf("Process %d\t->\t", p[i].id);
		scanf("%d", &p[i].bt);
	}

	//	Calculating the TAT
	p[0].wt = 0;
	for (i=1;i<n;i++) {
		p[i].wt = p[i-1].bt + p[i-1].wt;
	}

	for (i=0;i<n;i++)
		p[i].tat = p[i].wt + p[i].bt;

	//	Displaying the result...
	printf("\n\nPROCESS\tWT\tBT\tTAT\n");
	for (i=0;i<n;i++)
		printf("%d\t%d\t%d\t%d\n", p[i].id, p[i].wt, p[i].bt, p[i].tat);

	//	Displaying the GANTT chart
	printf("\n\nDisplaying the GANTT chart...\n");

	for (i=0;i<n;i++)
		printf("|\tP%d\t", p[i].id);
	printf("|\n");

	printf("0\t\t");
	for(i=0;i<n;i++)
		printf("%d\t\t", p[i].tat);
	printf("\nCompleted!\n");
}
