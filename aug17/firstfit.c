#include<stdio.h>

void firstFit (int blockSize[], int m, int processSize[], int n) {
	int i,j;
	int allocation[n];

	for (i=0; i<n; i++)
		allocation[i]=-1;

	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			if (blockSize[j] > processSize[i]) {
				allocation[i] = j;
				blockSize[j] -= processSize[i];
				break;
			}
		}
	}
	printf("\nProcessNumt\tProcessSize\tBlockNum\n");
	for (i=0; i<n;i++) {
		printf("%d\t\t\t%d\t\t\t",i+1, processSize[i]);
		if (allocation[i]!=-1) 
			printf("%d", (allocation[i]+1));
		else	printf("Not Allocated");
		printf("\n");
	}
}

void main() {
	int i,m,n;
	printf("Enter the number of blocks in memory...");
	scanf("%d", &m);

	printf("Reading the number of processes in input queue... ");
	scanf("%d", &n);

	printf("Reading block sizes... \n");
	int blockSize[m], processSize[n];

	for (i=0; i<m; i++)
		scanf("%d", &blockSize[i]);

	printf("\nReading process sizes....\n");
	for (i=0; i<n; i++)
		scanf("%d", &processSize[i]);

	firstFit(blockSize,m,processSize,n);
}
