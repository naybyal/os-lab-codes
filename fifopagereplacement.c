#include<stdio.h> 
int main()
{
	int pageFaults = 0, frames;
	int m, n, s, pages;
	printf("Enter the number of pages.. ");
	scanf("%d", &pages);
	printf("Enter the number of frames...");
	scanf("%d", &frames);
	int incomingStream[pages];
	printf("Reading incoming stream...\n");
	for(m=0;m<pages;m++) {
		scanf("%d", &incomingStream[m]);
	}

	printf("Incoming \t Frame 1 \t Frame 2 \t Frame 3");
	int temp[frames];
	for(m = 0; m < frames; m++)
	{
		temp[m] = -1;
	}

	for(m = 0; m < pages; m++)
	{
		s = 0;

		for(n = 0; n < frames; n++)
		{
		    if(incomingStream[m] == temp[n])
		    {
			s++;
			pageFaults--;
		    }
		}
		pageFaults++;

		if((pageFaults <= frames) && (s == 0))
		{
		    temp[m] = incomingStream[m];
		}
		else if(s == 0)
		{
		    temp[(pageFaults - 1) % frames] = incomingStream[m];
		}

		printf("\n");
		printf("%d\t\t\t",incomingStream[m]);
		for(n = 0; n < frames; n++)
		{
			printf(" %d\t\t\t", temp[n]);
		}
	}

	printf("\nTotal Page Faults:\t%d\n", pageFaults);
	return 0;
}
