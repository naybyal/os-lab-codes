#include<stdio.h>

struct process {
	int id, bt, rbt, tat, wt;
} p[50], x[50];

void main() {
	int n,i,j,k=1, cmp, netBurst=0, qt;

	printf("Reading the number of process.. ");
	scanf("%d", &n);

	printf("Reading the burst times for each process... \n\n");
	for (i=0; i<n; i++) {
		p[i].id = i+1;
		printf("PROCESS %d\t->\t", i+1);
		scanf("%d", &p[i].bt);
		netBurst += p[i].bt;
		p[i].rbt = p[i].bt;
	}

	printf("\nReading the time quanta... ");
	scanf("%d", &qt);

	cmp=0;
	x[0].tat = 0;
	int totalTAT=0, totalWT=0;
	while (cmp != netBurst) {
		for (i=0; i<n; i++) {
			if (p[i].rbt != 0) {
				x[k].id = i+1;
				if (p[i].rbt <= qt) {
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

	printf("\n\nPROCESS\tWT\tBT\tTAT\n");
	for (i=0; i<n; i++) 
		printf("%d\t%d\t%d\t%d\n", p[i].id, p[i].wt, p[i].bt, p[i].tat);

	printf("\n\n\t\t---GANTT CHART---\n\n");
	for (i=1;i<k;i++)
		printf("|\tP%d\t", x[i].id);
	printf("|\n");
	for (i=0;i<k;i++)
		printf("%d\t\t", x[i].tat);
	
	float avgTAT, avgWT;
	avgTAT = (float)totalTAT/n;
	avgWT = (float)totalWT/n;

	printf("\n\nAverage Turn Around Time = %.1f\n", avgTAT);
	printf("Average Waiting Time = %.1f", avgWT);

	printf("\n\n\t---Complete!---\n");

}
