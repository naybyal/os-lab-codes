#include<stdio.h>

int i,j,pageFaults, frames,pages,s;

void main() {
	pageFaults = 0; 

	//	Read the number of pages... 
	printf("Reading the number of pages... ");
	scanf("%d", &pages);

	//	Read the number of frames...
	printf("Reading the number of frames... ");
	scanf("%d", &frames);

	//	Declare an array of size(pages) for the incoming stream
	int incoming[pages];
	
	printf("Reading the incoming stream... \n");
	for (i=0; i<pages; i++)	
		scanf("%d", &incoming[i]);

	printf("Incoming\t");
	for (i=0;i<frames; i++) 
		printf("Frame %d\t", i+1);
	printf("\n");

	//	initialize a temp array of size frames and set each value to -1
	int temp[frames];

	for (i=0;i<frames;i++)
		temp[i] = -1;

	for (i=0;i<pages;i++) {
		s=0;
		for (j=0;j<frames;j++) { 
			if (incoming[i] == temp[j]) {
				s++;
				pageFaults--;
			}
		}
		pageFaults++;

		if (pageFaults <= frames && s==0)
			temp[i] = incoming[i];
		else if (s == 0) 
			temp[(pageFaults-1)%frames] = incoming[i];

		printf("\n%d\t\t\t", incoming[i]);
		for (j=0;j<frames;j++) 
			printf("%d\t\t\t", temp[j]);
	}

	printf("\nTotal Page faults = %d", pageFaults);
}
