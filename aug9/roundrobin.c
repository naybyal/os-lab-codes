#include<stdio.h>

struct process {
	int id, bt, rbt, tat, wt;
}p[50], out[50];

int qt, cmp, i,j,k, n, netBurst;

void main() {
	k=1;	netBurst=0;
	int totalTAT = 0, totalWT = 0;
	float avgTAT, avgWT;

	printf("Reading the number of processes... ");
	scanf("%d", &n);

	//	setting process ids.
	printf("Reading the burst time of each process... \n");
	for (i=0; i<n; i++) {
		p[i].id = i+1;
		printf("Process %d\t->\t", i+1);
		scanf("%d", &p[i].bt);
		p[i].rbt = p[i].bt;
		netBurst += p[i].bt;
	}

	//	read the time quanta
	printf("Reading the time quanta... ");
	scanf("%d", &qt);

	out[0].tat = 0; cmp = 0;

	while (cmp != netBurst) {
		for (i=0; i<n; i++) {
			if (p[i].rbt != 0) {
				out[k].id = i+1;
				if (p[i].rbt - qt <= 0) {
					out[k].wt = out[k-1].tat;
					out[k].bt = p[i].rbt;
					out[k].tat = out[k].bt + out[k].wt;

					p[i].rbt = 0;
					p[i].tat = out[k].tat;
					p[i].wt = p[i].tat - p[i].bt;

					cmp = out[k].tat; k++;
				} else {
					out[k].wt = out[k-1].tat;
					out[k].tat = out[k].wt + qt;
					p[i].rbt -= qt;

					cmp = out[k].tat; k++;
				}
			}
		}
	}

	//	Displaying the result;
	printf("\n\nPROCESS\tWT\tBT\tTAT");
	for (i=0;i<n;i++)
		printf("\n%d\t%d\t%d\t%d\t", p[i].id, p[i].wt, p[i].bt, p[i].tat);

	//	displaying the gantt chart
	printf("\n\n------GANTT CHART------\n");
	for (i=1;i<k;i++) 
		printf("|\tP%d\t", out[i].id);
	printf("|\n");

	for (i=0;i<k;i++)
		printf("%d\t\t", out[i].tat);
	printf("\n");
}
