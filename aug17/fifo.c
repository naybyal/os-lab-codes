#include<stdio.h>


void main() {
	int pages, frames, i,j, pageFaults=0,s;
	
	printf("\nEnter the number of pages : ");
	scanf("%d", &pages);

	printf("Enter the number of frames : ");
	scanf("%d", &frames);

	int incoming[pages], temp[frames];
	
	printf("Reading the incoming requests... \n");
	for (i=0;i<pages; i++) 
		scanf("%d", &incoming[i]);
	printf("\n\nINCOMING\t");
	for (i=0;i<frames;i++) {
		printf("FRAME %d\t", i+1);
		temp[i] = -1;
	}

	for (i=0; i<pages; i++) {
		s=0;
		for(j=0;j<frames;j++) {
			if (incoming[i] == temp[j]) {
				s++;
				pageFaults--;
			}
			pageFaults++;	
		}
		if (pageFaults<=frames && s==0) {
                        temp[i] = incoming[i];
                } else if (s == 0) {
                        temp[(pageFaults-1)%frames] = incoming[i];
                }

                printf("\n%d\t\t\t", incoming[i]);
                for (j=0;j<frames;j++)
			printf("%d\t\t\t", temp[j]);
	}

	printf("\n\nTotal page faults = %d", pageFaults);
}
