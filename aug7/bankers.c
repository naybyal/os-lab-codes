#include<stdio.h>
#include<stdlib.h>

int i,j,k,numProcess, numResource, idx = 0;

int available[10], state[10], maxClaim[10][10], allocResource[10][10], need[10][10];

int sequence[10];

void main() {
	int change;
	printf("Reading the number of procesess.. ");
	scanf("%d", &numProcess);

	printf("Reading the number of resources... ");
	scanf("%d", &numResource);

	printf("Reading the Allocated Resource table... \n");
	for (i=0;i<numProcess;i++) {
		printf("--PROCESS %d---\n", i+1);
		for (j=0;j<numResource;j++) 
			scanf("%d", &allocResource[i][j]);
	}

	printf("\nReading the Max Claim table...\n");
	for (i=0;i<numProcess;i++) {
		printf("---PROCESS %d---\n", i+1);
		for (j=0;j<numResource;j++)
			scanf("%d", &maxClaim[i][j]);
	}

	printf("Reading the available resources.. \n");
	for (i=0; i<numResource; i++)
		scanf("%d", &available[i]);

	//	Calculating the NEED matrix
	for (i=0; i<numProcess; i++) {
		for (j=0; j<numResource; j++) 
			need[i][j] = maxClaim[i][j] - allocResource[i][j];
	}

	//	Displaying the NEED matrix
	printf("\n---NEED MATRIX---\n");
	for (i=0; i<numProcess; i++) {
		for (j=0; j<numResource; j++) 
			printf("%d\t", need[i][j]);
		printf("\n");
	}

	//	Running the safety algorithm....
	for (j=0;j<numResource;j++) {
		for (i=0;i<numProcess;i++) {
			if (state[i] == 0) {
				change = 0;
				for (k=0; k<numResource; k++) {
					if (need[i][k] > available[k]) {
						change = 1;
						break;
					}
				}

				if (change == 0) {
					sequence[idx++] = i;
					for (k=0; k<numResource; k++)
						available[k] += allocResource[i][k];
					state[i] = 1;
				}
			}
		}
	}

	change = 1;
	for (i=0; i<numProcess; i++) {
		if (state[i] == 0) {
			change = 0;
			printf("\n--The system is not in Safe State.--\n"); 
			break;
		}
	}

	if (change == 1) {
		printf("\n Safe sequence : ");
		for (i=0; i<numProcess-1; i++)	
			printf("P%d -> ", sequence[i]);
		printf("P%d\n", sequence[numProcess-1]);
	}	
}
