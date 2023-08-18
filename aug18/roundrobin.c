#include<stdio.h>

struct process {
	int id, bt, rbt, wt, tat;
} p[69], x[69];

void main() {
	int totalTAT=0, totalWT=0;
	int n,i,j,k=1,cmp=0,netBurst=0,qt;

	printf("Reading the number of processes.. ");
	scanf("%d", &n);
	
	printf("Reading the burst times of each process.... \n");
	for (i=0; i<n; i++) {
		p[i].id = i+1;
		printf("\nPROCESS %d\t->\t", p[i].id);
		scanf("%d", &p[i].bt);
		p[i].rbt = p[i].bt;
		netBurst += p[i].bt;
	}

	printf("Reading the time quanta... ");
	scanf("%d", &qt);

	x[0].tat = 0;
	while (cmp != netBurst) {
		for (i=0;i<n; i++) {
			if (p[i].rbt!=0) {
				x[k].id = i+1;
				if (p[i].rbt - qt <= 0) {
					x[k].wt = x[k-1].tat;
					x[k].bt = p[i].rbt;
					x[k].tat = x[k].wt +x[k].bt;

					p[i].rbt = 0;
					p[i].tat = x[k].tat;
					p[i].wt = p[i].tat - p[i].bt;

					k++;
					cmp = x[k].tat;

					totalTAT += p[i].tat;
					totalWT += p[i].wt;
				} else {
					x[k].wt = x[k-1].tat;
					x[k].tat = x[k].wt +  qt;
					p[i].rbt -= qt;

					cmp = x[k].tat;
					k++;
				}
			}
		}
	}
}
