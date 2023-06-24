#include<stdio.h>
#include<stdlib.h>

int i, j, k, numOfProcess, numOfResource, idx=0;

int available[10], state[10], maxClaim[10][10], allocResource[10][10], need[10][10];

int sequence[10];

void main() {
	int change;
	printf("Reading the number of Processes... ");
	scanf("%d", &numOfProcess);

	printf("Reading the number of Resources... ");
	scanf("%d", &numOfResource);

	printf("Reading the Allocated Resource Table... \n");
	for (i=0; i<numOfProcess; i++) {
		printf("---Process %d---\n", i+1);
		for (j=0; j<numOfResource; j++) {
			scanf("%d", &allocResource[i][j]);
		}
	}

	printf("\nReading the Max Claim Table... \n");
	for (i=0; i<numOfProcess; i++) {
		printf("---Process %d---\n",i+1);
		for (j=0; j<numOfResource; j++) 
			scanf("%d", &maxClaim[i][j]);
		state[i] = 0;
	}

	printf("Reading the Available Resources... \n");
	for (i=0; i<numOfResource; i++) 
		scanf("%d", &available[i]);

	// Calculating the NEED MATRIX
	for(i=0; i<numOfProcess; i++) {
		for (j=0; j<numOfResource; j++) {
			need[i][j] = maxClaim[i][j] - allocResource[i][j];
		}
	}

	// Display the need matrix
	printf("The Need Matrix is... \n");
	for (i=0; i<numOfProcess; i++) {
		for (j=0; j<numOfResource; j++)
			printf("%d\t", need[i][j]);
		printf("\n");
	}
	// Running the SAFETY Algorithm
	
	for (j=0; j<numOfResource; j++) {
		for (i=0; i<numOfProcess; i++) {
			if (state[i] == 0) {
				change = 0;
				for (k=0; k<numOfResource; k++) {
					if (need[i][k] > available[k]) {
						change = 1;
						break;
					}
				}
				if (change == 0) {
					sequence[idx++] = i;
					for (k=0; k<numOfResource; k++)
						available[k] += allocResource[i][k];
					state[i] = 1;					
				}
			}
		}
	}
	change = 1;
	for (i=0; i<numOfProcess; i++) {
		if (state[i] == 0) {
			change = 0;
			printf("\nThe system is NOT in SAFE state.\n");
			break;
		}
	}

	if (change == 1) {
		printf("\n\nThe system is in SAFE state\n");
		printf("\nSafe sequence : ");
		for (i=0; i<numOfProcess-1; i++) 
				printf("P%d -> ",sequence[i]);
		printf("P%d\n\n", sequence[numOfProcess-1]);
	}
	printf("\n---Complete!---\n");
}
