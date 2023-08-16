#include<stdio.h>

void main() {
	
	int numProcess, numResource, i,j,k;
	int maxClaim[10][10], allocRes[10][10], need[10][10], available[10], state[10], idx=0;
	int sequence[10];

	printf("Enter number of processes : ");
	scanf("%d", &numProcess);

	printf("Enter number of resources : ");
	scanf("%d", &numResource);

	printf("Reading the max claim table... \n");
	for (i=0; i<numProcess; i++) {
		printf("\n---PROCESS %d---\n", i+1);
		state[i] = 0;
		for (j=0; j<numResource; j++) 
			scanf("%d", &maxClaim[i][j]);
	}

	printf("Reading the allocated resources for each process... \n");
	for (i=0; i<numProcess; i++) {
                printf("\n---PROCESS %d---\n", i+1);
                for (j=0; j<numResource; j++)
                        scanf("%d", &allocRes[i][j]);
        }

	printf("Reading the available resources... \n");
	for (i=0; i<numResource; i++)
		scanf("%d", &available[i]);

	//	computing the need matrix.
	
	for (i=0; i<numProcess; i++) {
		for (j=0; j<numResource; j++)
			need[i][j] = maxClaim[i][j] - allocRes[i][j];
	}

	//	displaying the need matrix.
	
	printf("\n---NEED MATRIX---\n");
	for (i=0; i<numProcess; i++) {
		for (j=0; j<numResource; j++)
			printf("%d\t", need[i][j]);
		printf("\n");
	}

	//	running the safety algorithm
	int change;
	for (k=0; k<numResource; k++) {
		for (i=0; i<numProcess; i++) {
			if (state[i] == 0) {
				change = 0;
				for (j=0; j<numResource; j++) {
					if (need[i][j] > available[j]) {
						change = 1;
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

	change = 0;
	for (i=0; i<numProcess; i++) {
		if (state[i] != 1) {
			change = 1;
			printf("\nThe system is in UNSAFE STATE\n");
			break;
		}
	}

	if (change == 0) {
		printf("\nThe system is in SAFE STATE\n");
		printf("The safe sequence : ");
		for (i=0; i<numProcess; i++) 
			printf("%d\t", sequence[i]);

	}

}
