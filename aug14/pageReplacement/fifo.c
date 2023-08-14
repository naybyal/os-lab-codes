#include<stdio.h>

int pages,frames,pageFaults, flag;

void main() {
	pageFaults = 0;
	int i,j;

	//	Read the number of pages and frames
	
	printf("\nReading the number of pages\t->\t");
	scanf("%d", &pages);

	printf("Reading the number of frames\t->\t");
	scanf("%d", &frames);

	//	Declare an array incStream of size, pages
	int incStream[pages];

	//	Read the incoming stream
	printf("\n----READING INCOMING STREAM----\n");
	for (i=0;i<pages; i++) 
		scanf("%d", &incStream[i]);

	//	Declare a temp array of size frames
	int temp[frames];

	//	Initialize all values of temp array to -1
	for (i=0; i<frames; i++)
		temp[i] = -1;
	//	Displaying the stream
	printf("\n\nIncoming\t\t");
	for (i=0; i<frames; i++) {
		printf("Frame %d\t\t\t", i+1);
	}
	
	for (i=0; i<pages; i++) {
		flag = 0;
		for (j=0; j<frames; j++) {
			if (incStream[i] == temp[j]) {
				flag++;
				pageFaults--;
			}	
		}
		pageFaults++;

		if (pageFaults <= frames && flag == 0) {
			temp[i] = incStream[i];
		} else if (flag == 0) {
			temp[(pageFaults-1)%frames] = incStream[i];
		}
		printf("\n");
		printf("%d\t\t\t", incStream[i]);
		for (j=0; j<frames; j++) {
	 		if (temp[j] == -1)
				printf("%d\t\t\t", temp[j]);	
			else	printf(" %d\t\t\t", temp[j]);
		}
	}
	float val = (float)pageFaults/pages;
	// Calculating the hit ratio
	printf("\n\nTotal page faults\t->\t%d", pageFaults);
	printf("\nHit Ratio\t\t->\t%d/%d = %.1f\n\n", pageFaults, pages, val);
}
