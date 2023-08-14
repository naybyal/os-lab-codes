#include<stdio.h>

struct process {
	int id, bt, rbt, tat, wt;
} p[50], x[50];


void main() {

	int netBurst = 0, i, j, k = 1, cmp, qt, n;

	printf("Reading the number of process : ");
	scanf("%d", &n);
	
	//	Read burst times of each process and actively initialize the id's of each process
	
	printf("Reading the burst times of each process...\n");
	for (i=0; i<n; i++) {
		p[i].id = i+1;
		printf("\nPROCESS %d\t->\t", p[i].id);
		scanf("%d", &p[i].bt);
		p[i].rbt = p[i].bt;
		netBurst += p[i].bt;
	}

	//	Read the time quanta
	
	printf("Reading the time quanta\t->\t");
	scanf("%d", &qt);

	cmp = 0;
	x[0].tat = 0;
	while (cmp != netBurst) {
		for (i=0; i<n; i++) {
			if (p[i].rbt != 0) {
				x[k].id = i+1;

				if (p[i].rbt - qt <= 0) {
					x[k].wt = x[k-1].tat;
					x[k].bt = p[i].rbt;
					x[k].tat = x[k].wt + x[k].tat;

					p[i].rbt = 0;
					p[i].tat = x[k].tat;
					p[i].wt = p[i].tat - p[i].bt;

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

	//	rest will follow...
}
