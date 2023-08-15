#include<stdio.h>
#include<stdlib.h>

int maxClaim[10][10], numResource, numProcess, need[10][10], allocRes[10][10], sequence[10], available[10], state[10];
int i,j,k,change,idx=0;

void main() {
	printf("Reading the number of processes... ");
	scanf("%d",&numProcess);

	printf("Reading the number of resource... ");
	scanf("%d", &numResource);

	printf("Reading the allocated resource table... \n");
	for (i=0; i<numProcess; i++) {
		printf("----PROCESS %d----\n", i+1);
		for (j=0; j<numResource; j++) {
			scanf("%d", &allocRes[i][j]);
		}
	}

	printf("\n\nReading the Max Claim Table... \n");
	for (i=0; i<numProcess; i++) {
		printf("----PROCESS %d----\n", i+1);
		for (j=0; j<numResource; j++) {
			scanf("%d", &maxClaim[i][j]);
		}
		state[i] = 0;		
	}

	printf("\n\nReading the available resource...\n");
	for (i=0; i<numResource; i++)
		scanf("%d", &available[i]);

	//	Calculating the need matrix...
	for (i=0; i<numProcess; i++) {
		for (j=0; j<numResource; j++) {
			need[i][j] = maxClaim[i][j] - allocRes[i][j];
		}
	}

	//	Displaying the need matrix... 
	printf("\n\n---NEED MATRIX---\n\n");
	for (i=0; i<numProcess; i++) {
		for (j=0;j<numResource;j++)
			printf("%d\t", need[i][j]);
		printf("\n");
	}

	//	Running the Safety Algorithm
	for (k=0;k<numResource;k++) {
		for (i=0; i<numProcess; i++) {
			if (state[i] == 0) {
				change = 0;
				for (j=0; j<numResource; j++) {
					if (need[i][j] > available[j]) {
						change++;
						break;
					}
				}

				if (change == 0) {
					sequence[idx++] = i+1;
					for (j=0; j<numResource; j++)
						available[j] += allocRes[i][j];
					state[i] = 1;
				}
			}
		}
	}

	change = 1;

	for (i=0; i<numProcess; i++) {
		if (state[i] == 0) {
			change = 0;
			printf("\nThe system is in an UNSAFE state.\n");
			break;
		}
	}

	if (change == 1) {
		printf("Safe sequence : ");
		for (i=0; i<numProcess-1; i++)
			printf("%d -> ", sequence[i]);
		printf("%d\n\n", sequence[numProcess-1]);
	}

}
