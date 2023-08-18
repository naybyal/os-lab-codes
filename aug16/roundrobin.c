#include<stdio.h>

struct process {
	int id, bt, rbt, tat, wt;
}p[50],x[50];

void main() {
	int k=1, i,j,n, netBurst = 0, cmp;

	printf("Enter the number of processes : ");
	scanf("%d", &n);

	printf("\nReading the burst times of each process... \n");
	for (i=0; i<n; i++) {
		p[i].id = i+1;
		printf("Process %d\t->\t", i+1);
		scanf("%d", &p[i].bt);
		p[i].rbt = p[i].bt;
		netBurst += p[i].bt;
	}

	printf("\nReading time quanta... ");
	int qt;
	scanf("%d", &qt);

	x[0].tat = 0;
	cmp = 0;
	int totalTAT=0, totalWT=0;
	while (cmp != netBurst) {
		for (i=0; i<n; i++) {
			if (p[i].rbt != 0) {
				x[k].id = i+1;
				if (p[i].rbt - qt <= 0) {
					x[k].wt = x[k-1].tat;
					x[k].bt = p[i].rbt;
					x[k].tat = x[k].wt + x[k].bt;

					p[i].rbt = 0;
					p[i].tat = x[k].tat;
					p[i].wt = p[i].tat - p[i].bt;
					
					totalTAT += p[i].tat;
					totalWT += p[i].wt;
						
					cmp = x[k].tat;
					k++;

					
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

	printf("\n\nPROCESS\tWT\tTAT\tBT\n");
	for (i=0; i<n; i++) {
		printf("%d\t%d\t%d\t%d\n", p[i].id, p[i].wt, p[i].tat, p[i].bt);
	}

	printf("\n\t-----GANTT CHART-----\n\n");
	for (i=1; i<k; i++)
		printf("|\tP%d\t", x[i].id);
	printf("|\n");

	for (i=0; i<k; i++) 
		printf("%d\t\t", x[i].tat);
	printf("\n");

	float avgWT, avgTAT;
	avgTAT = (float)totalTAT/n;
	avgWT = (float)totalWT/n;

	printf("\nAverage Turn Around Time : %.1f ms\n", avgTAT);
	printf("Average Waiting Time : %.1f ms\n\n", avgWT);
}
