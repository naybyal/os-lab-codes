#include<stdio.h>

struct process {
	int id, bt, rbt, wt, tat;
}p[60], x[60];

void main() {

	int n,i,qt, netBurst=0, cmp, k=1;

	int totalTAT=0, totalWT=0;
	float avgTAT, avgWT;
	
	printf("Reading the number of processes... ");
	scanf("%d",&n);

	printf("Reading the burst times of each process... \n\n");
	for (i=0; i<n; i++) {
		p[i].id = i+1;
		printf("Process %d\t->\t", p[i].id);
		scanf("%d", &p[i].bt);
		p[i].rbt = p[i].bt;
		netBurst += p[i].bt;
	}
	
	printf("Reading the time quanta... ");
	scanf("%d", &qt);
	
	cmp=0;
	x[0].tat = 0;
	
	while (cmp != netBurst) {
		for (i=0;i<n;i++) {
			if (p[i].rbt != 0) {
				x[k].id = i+1;
				if (p[i].rbt-qt <= 0) {

					x[k].wt = x[k-1].tat;
					x[k].bt = p[i].rbt;
					x[k].tat = x[k].bt + x[k].wt;
					
					p[i].rbt = 0;
					p[i].tat = x[k].tat;
					p[i].wt = p[i].tat - p[i].bt;

					
					cmp = x[k].tat;
					k++;

					totalWT += p[i].wt;
					totalTAT += p[i].tat;		
						
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

	printf("\n\nPROCESS\tWT\tBT\tTAT");
	for (i=0;i<n;i++) {
		printf("\n%d\t%d\t%d\t%d", p[i].id, p[i].wt, p[i].bt, p[i].tat);
	}
	printf("\n\n");
	
	avgTAT = (float)totalTAT/n;
	avgWT = (float)totalWT/n;

	printf("Average TAT\t->\t%.1f\n",avgTAT);
	printf("Average WT\t->\t%.1f\n",avgWT);

	//	Displaying the GANTT chart
	printf("---GANTT CHART---\n\n");
	for (i=1;i<k;i++)
		printf("|\tP%d\t", x[i].id);
	printf("|\n");
	
	for(i=0; i<k; i++)
		printf("%d\t\t", x[i].tat);
	printf("\n\n");
}
