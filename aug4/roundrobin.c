#include<stdio.h>

struct process {	
	int id, btime, rbt, tat, wt;
}p[50], x[50];

void main() {
	int i,j,k=1, timeQuanta, n, netBurst=0;
	int totalTAT=0, totalWT=0;

	printf("Reading the number of processes... ");
	scanf("%d", &n);

	printf("Reading the burst times of each process...\n");
	for (i=0; i<n ;i++) {
		p[i].id = i+1;
		printf("Process %d\t->\t", i+1);
		scanf("%d", &p[i].btime);

		// initializing rbt for each processes..
		p[i].rbt = p[i].btime;

		netBurst += p[i].btime;
	}

	// Reading the time splice...
	printf("Reading the time quanta... ");
	scanf("%d", &timeQuanta);

	// initialize the tat of the first process with 0
	x[0].tat = 0;

	int cmp = 0;

	while (cmp != netBurst) {
		for (i=0;i<n;i++) {
			if (p[i].rbt != 0) {
				x[k].id = i+1;
				if (p[i].rbt - timeQuanta <= 0) {
					x[k].wt = x[k-1].tat;
					x[k].btime = p[i].rbt;
					x[k].tat = x[k].wt + x[k].btime;

					p[i].rbt = 0;
					p[i].tat = x[k].tat;
					p[i].wt = p[i].tat - p[i].btime;

					cmp = x[k].tat;
					k++;

					totalTAT += p[i].tat;
					totalWT += p[i].wt;
				} else {
					x[k].wt - x[k-1].tat;
				       	x[k].tat = x[k].wt + timeQuanta;
					p[i].rbt -= timeQuanta;

					cmp = x[k].tat;
					k++;	
				}
			}
		}
	}

	printf("\nPROCESS\tWT\tTAT\tBT\n");
	for (i=0;i<n;i++) 
		printf("%d\t%d\t%d\t%d\n", p[i].id, p[i].wt, p[i].tat, p[i].btime);
	printf("\n");

	float avgTAT = (float)totalTAT/n;
	float avgWT = (float)totalWT/n;

	printf("\nAverage TAT : %.1f\nAverage WT : %.1f\n", avgTAT, avgWT);
} 
