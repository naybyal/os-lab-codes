#include<stdio.h>

void main() {
	int sequence[10], maxClaim[10][10], state[10], allocRes[10][10], available[10], need[10][10];
	int numProcess, numResource, i, j, k, idx=0;

	printf("\nReading the number of processes... ");
	scanf("%d", &numProcess);

	printf("Reading the number of resources... ");
	scanf("%d", &numResource);
	
	printf("\n");
	
	//	reading the max claim table
	
	printf("Reading the MAX CLAIM table... \n");
	for (i=0; i<numProcess; i++) {
		printf("---PROCESS %d---", i+1);
		state[i] = 0;
		for (j=0; j<numResource; j++)
			scanf("%d", &maxClaim[i][j]);
	}

	//	reading the allocated resources for each process
	
	printf("\nReading the ALLOCATED RESOURCES TABLE...\n");
	for (i=0; i<numProcess; i++) {
                printf("---PROCESS %d---", i+1);
                for (j=0; j<numResource; j++)
                        scanf("%d", &allocRes[i][j]);
        }

	//	reading the available resources
	
	printf("\nReading the available resources...\n");
	for (i=0; i<numResource; i++)
		scanf("%d", &available[i]);

	//	computing the NEED matrix...
	
	for (i=0;i<numProcess;i++) {
		for (j=0;j<numResource;j++) 
			need[i][j] = maxClaim[i][j] - allocRes[i][j];
	}

	printf("\n---NEED MATRIX---\n");
	for (i=0;i<numProcess;i++) {
		for (j=0;j<numResource;j++)
			printf("%d\t", need[i][j]);
		printf("\n");
	}

	//	running the safety algorithm
	int change;
	for (k=0;k<numResource;k++) {
		for (i=0;i<numProcess;i++) {
			if (state[i] == 0) {
				change = 0;
				for (j=0;j<numResource;j++) {
					if (need[i][j] > available[j]) {
						change =1;
						break;
					}
				}
				if (change == 0) {
					sequence[idx++] = i+1;
					for (j=0;j<numResource;j++)
						available[j] = allocRes[i][j];
					state[i]=1;
				}
			}
		}
	}

	change = 0;	//	reusing the code
	for (i=0; i<numProcess; i++) {
		if (state[i] != 1) {
			printf("\nThe system is in Unsafe state!\n");
			change = 1;
			break;
		}
	}

	if (change == 0) {
		printf("Safe sequence : ");
		for (i=0;i<numProcess;i++)
			printf("%d\t", sequence[i]);
	}

	printf("\n");
}
