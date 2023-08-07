#include<stdio.h>

struct process {
	int bt,rbt,wt,tat,id;
}p[50], x[50];

void main() {
	int i,j,n, totalTAT=0, totalWT=0, cmp, netBurst=0, qt;
	float avgTAT, avgWT;

	//	Read the number of process....
	printf("Reading the number of processes.. ");
	scanf("%d", &n);

	//	initializing pid and reading burst times of each process...
	printf("Reading the burst times of each processes...\n");
	for (i=0; i<n; i++) {
		p[i].id = i+1;
		printf("Process %d\t->\t",p[i].id);
		scanf("%d", &p[i].bt);
		p[i].rbt = p[i].bt;
		netBurst += p[i].bt;
	}

	//	Read the time slice...
	printf("Reading the time quanta.. ");
	scanf("%d", &qt);

	x[0].tat = 0;

	cmp = 0;	
	int k=1;
	while (cmp != netBurst) {
		for (i=0; i<n; i++) {
			if (p[i].rbt != 0) {
				x[i].id = i+1;
				if (p[i].rbt-qt <= 0) {
					x[k].wt = x[k-1].tat;
					x[k].bt = p[i].rbt;
					x[k].tat = x[k].wt + x[k].bt;

					p[i].rbt = 0;
					p[i].tat = x[k].tat;
					p[i].wt = p[i].tat - p[i].bt;

					cmp = x[k].tat;
					k++;

					totalTAT += p[i].tat;
					totalWT += p[i].wt;
				} else {
					x[k].wt = x[k-1].tat;
					x[k].tat = x[k].wt + qt;
					p[i].rbt -= qt;

					cmp = x[k].tat;
					k++;
				}
			}
		}
	}

	printf("\nPROCESS\tWT\tTAT\tBT");
	for (i=0; i<n; i++) {
		printf("\n%d\t%d\t%d\t%d\n", p[i].id, p[i].wt, p[i].tat, p[i].bt);
	}
	printf("\n");

	avgTAT = (float)totalTAT/n;
	avgWT = (float)totalWT/n;
	printf("Average TAT\t->\t%.1f ms", avgTAT);
	printf("\nAverage WT\t->\t%.1f ms", avgWT);

	//	Displaying the GANTT chart
	printf("\n\n------GANTT CHART------\n\n");
	for (i=1;i<k;i++) 
		printf("|\tP%d\t", x[i].id);
	printf("|\n");
	for (i=0; i<k; i++) 
		printf("%d\t\t", x[i].tat);
	printf("\n");
}	
