#include<stdio.h>

int sequence[10], state[10], maxClaim[10][10], allocRes[10][10], available[10], need[10][10];
int numProcess, numResource, idx, change;

void main() {
	idx = 0;
	int i,j,k;

	//	Read the number of process and resources...
	
	printf("Enter the number of processes... ");
	scanf("%d", &numProcess);
	printf("Enter the number of resources... ");
	scanf("%d", &numResource);

	//	Read the MAX CLAIM TABLE and ALLOCATED RESOURCES for each process...
	
	printf("\n\n----READING MAX CLAIM TABLE----\n\n");
	for (i=0; i<numProcess; i++) {
		printf("==PROCESS %d==\n", i+1);
		for (j=0; j<numResource; j++) {
			scanf("%d", &maxClaim[i][j]);
		}
	}

	printf("\n\n----READING ALLOCATED RESOURCES----\n\n");
	for (i=0; i<numProcess; i++) {
		printf("==PROCESS %d==\n", i+1);
		for (j=0; j<numResource; j++) {
			scanf("%d", &allocRes[i][j]);
		}
		state[i] = 0;
	}
	
	// Read the available resources...
	printf("\n\n----READING AVAILABLE RESOURCES----\n\n");
	for (i=0; i<numResource; i++) 
		scanf("%d", &available[i]);

	//	Compute the NEED matrix (need[i][j] =  maxClaim[i][j] - allocRes[i][j])
	
	for (i=0; i<numProcess; i++) {
		for (j=0; j<numResource; j++) 
			need[i][j] =  maxClaim[i][j] - allocRes[i][j];
	}

	//	Display the NEED matrix
	
	printf("\n\n----NEED MATRIX!----\n");
	for (i=0; i<numProcess; i++) {
		for (j=0; j<numResource; j++) 
			printf("%d\t", need[i][j]);
		printf("\n");
	}

	//	Running the SAFETY algorithm
	
	for (k=0; k<numResource; k++) {
		for (i=0; i<numProcess; i++) {
			if (state[i] == 0) {
				//	No need to consider a process for this round if need > available
				
				change = 0;	//	This acts like a flag
				
				for (j=0; j<numResource; j++) {
					if (need[i][j] > available[j]) {
						change = 1;
						break;
					}
				}
				
				//	if need < available, add the process to the sequence
				//	and increment the available resource of the process with its allocated resource
				if (change == 0) {
					sequence[idx++] = i+1;
					for (j=0; j<numResource; j++)
						available[j] += allocRes[i][j];
					//	set the state of the process to 1
					state[i] = 1;
				}
			}
		}
	}

	change = 0;	//	reuse the code for optimization

	//	if any of the state is 0, the system is in unsafe state
	
	for (i=0; i<numProcess; i++) {
		if (state[i] == 0) {
			change = 1;
			printf("The system is in an UNSAFE state.\n");
			break;
		}
	}
	
	//	if the system is in safe state, display the safe sequence.
	
	if (change == 0) {
		printf("\n\nSafe sequence : ");
		for (i=0; i<numProcess-1; i++) 
			printf("%d -> ", sequence[i]);
		printf("%d", sequence[numProcess-1]);
	}

	printf("\n");
}	
