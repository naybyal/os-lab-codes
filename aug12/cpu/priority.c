#include<stdio.h>

int n,i,j;

struct process{
	int id, bt, tat, wt, prio;
}p[50], temp;

void main() {
	printf("\n---PRIORITY CPU SCHEDULING---\n\n");
	printf("Reading the number of processes... ");
	scanf("%d", &n);

	//	Reading the burst times of each process... 
	printf("Reading the burst times and priorities (1, the highest)... \n");
	for (i=0;i<n;i++) {
		p[i].id = i+1;
		printf("====Process %d====\n", p[i].id);
		printf("=Burst time\t->\t");
		scanf("%d", &p[i].bt);
		printf("=Priority\t->\t");
		scanf("%d", &p[i].prio);

	}

	//	sorting by priority
	for (i=0;i<n;i++) {
		for (j=0;j<n-i-1;j++) {
			if (p[j].prio > p[j+1].prio) {
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}

	//	Calculating the TAT
	p[0].wt = 0;
	for (i=1;i<n;i++) {
		p[i].wt = p[i-1].bt + p[i-1].wt;
	}

	for (i=0;i<n;i++)
		p[i].tat = p[i].wt + p[i].bt;

	//	Displaying the result...
	printf("\n\nPROCESS\tPRIO\tWT\tBT\tTAT\n");
	for (i=0;i<n;i++)
		printf("%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].prio, p[i].wt, p[i].bt, p[i].tat);

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
