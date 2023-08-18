#include<stdio.h>

void main() {
	int frag[20], nb, np, b[20], p[20], low=9999, i,j, temp;
	static int barray[20], parray[20];

	printf("Num blocs : ");
	scanf("%d", &nb);

	printf("num process :");
	scanf("%d", &np);
	printf("reading process sizes\n");
	for (i=1; i<=np; i++)
		scanf("%d", &p[i]);
	printf("reading block sizes\n");
	for (i=1; i<=nb; i++)
		scanf("%d", &b[i]);

	for (i=1; i<=np; i++) {
		for (j=1; j<=nb; j++) {
			if (barray[j] != 1) {
				temp = b[j]-p[i];
				if (temp>=0 && low > temp) {
					parray[i] = j;
					low = temp;
				}
			}
		}
		frag[i] = low;
		barray[parray[i]] = 1;
		low = 10000;
	}

	printf("PROCESS\tSIZE\tBlock\tSize\tFragment");
	for (i=1; i<=np; i++) {
		if (parray[i]!=0)
			printf("\n%d\t%d\t%d\t%d\t%d", i, p[i], parray[i], b[parray[i]], frag[i]);
		else
			printf("\n%d\t%d\tNOT ALLOCATED", i, p[i]);
	}
	printf("\n");
}
