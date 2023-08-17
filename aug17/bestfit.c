#include<stdio.h>
void sort(int a[], int n) {
	int i, j, temp;
	for(i=0; i<n; i++) {
		for (j=0;j<n-i-1; j++) {
			if (a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}	
		}
	}
}

void bestFit (int blockSize[], int m, int processSize[], int n) {
	int i,j;
	int allocation[n];
	for (i=0; i<n; i++)
		allocation[i]=-1;
	//sort(blockSize, m);
	//sort(processSize, n);
	for (i=0; i<n; i++) {
		int indexPlaced = -1;
		for (j=0; j<m; j++) {
			if (blockSize[j] >= processSize[i]) {
				if (indexPlaced == -1)	indexPlaced = j;
				else if (blockSize[j] < blockSize[indexPlaced])
					indexPlaced = j;
			}
		}
		if (indexPlaced != -1) {
			allocation[i] = indexPlaced;
			blockSize[indexPlaced] -= processSize[i];
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

	bestFit(blockSize,m,processSize,n);
}
