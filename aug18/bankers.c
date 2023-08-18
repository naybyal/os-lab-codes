#include<stdio.h>

void main() {
	int i,j, numProcess, numResource, idx=0;
	int sequence[10], maxClaim[10][10], allocRes[10][10], available[10], need[10][10];
	int state[10];
	printf("Reading the number of process... ");
	scanf("%d", &numProcess);
	printf("Reading the number of resources... ");
	scanf("%d", &numResource);

	printf("Reading the max claim table... \n");
	for(i=0; i<numProcess; i++) {
		state[i] = 0;
		printf("\n--PROCESS %d--\n", i+1);
		for (j=0; j<numResource; j++)
			scanf("%d", &maxClaim[i][j]);
	}

	printf("Reading the allocated table... \n");
        for(i=0; i<numProcess; i++) {
                printf("\n--PROCESS %d--\n", i+1);
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

	printf("\t\t---	NEED MATRIX ---\n");
	for (i=0; i<numProcess; i++) {
		for (j=0; j<numResource; j++)
			printf("%d\t", need[i][j]);
		printf("\n");
	}
	
	//	running the safety algorithm
	int change = 0,k;
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
					state[i] = 1;
					sequence[idx++] = i+1;
					for (j=0; j<numResource; j++) 
						available[j] += allocRes[i][j];
				}
			}
		}
	}

	change = 0;
	for (i=0; i<numProcess; i++) {
		if (state[i]!=1) {
			printf("\nSystem is in UNSAFE STATE..\n");
			change = 1;
			break;
		}
	}

	if (change == 0) 
	{
		printf("\n\nSafe sequence : ");
		for (i=0; i<numProcess; i++)
			printf("%d\t", sequence[i]);
	}

	printf("\n");
}
