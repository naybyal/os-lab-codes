#include<stdio.h>



void main() {
	int i,j, pages, frames, pageFaults=0,s;

	printf("Reading the number of pages : ");
	scanf("%d", &pages);

	printf("Reading the number of frames : ");
	scanf("%d", &frames);

	//	intializing incomingPages[] with size, pages
	int incStream[pages], temp[frames];

	printf("Reading the incoming stream ....\n\n");
	for (i=0; i<pages; i++)
		scanf("%d", &incStream[i]);
	

	//	filling temp array with -1
	printf("\n\nINCOMING\t");
	for (i=0;i<frames; i++) {
		printf("FRAME %d\t", i+1);
		temp[i] = -1;
	}
	printf("\n");

	for (i=0; i<pages; i++) {
		s=0;
		for (j=0; j<frames; j++) {
			if (incStream[i] == temp[j]) {
				s++;
				pageFaults--;
			}
			pageFaults++;
		}

		if (pageFaults<=frames && s==0) {
			temp[i] = incStream[i];
		} else if (s == 0) {
			temp[(pageFaults-1)%frames] = incStream[i];
		}

		printf("\n%d\t\t\t", incStream[i]);
		for (j=0; j<frames; j++)
			printf("%d\t\t\t", temp[j]);
	}
	printf("\n\n\nTotal page faults = %d", pageFaults);
}
