#include<stdio.h>

void fcfs(int n, int a[], int hd) {
	int tst=0, x, i;
	for (i=0; i<n; i++) {
		x = a[i] - hd;
		if (x < 0)
			x = -x;
		tst += x;
		hd = a[i];
	}

	printf("\nScheduled sequence : ");
	for (i=0; i<n; i++) {
		printf("%d\t", a[i]);
	}

	printf("\nTotal seek time = %d ms\n", tst);
}

void scan(int n, int a[], int hd) {
	int x, tst = 0, i, j , mov, size, index;
	printf("Reading the size of the buffer : ");
	scanf("%d", &size);
	size--;

	printf("Reading the head movement direction (0 for low, 1 for high) : ");
	scanf("%d", &mov);
	//	Sort the requests
	for (i=0; i<n-1; i++) {
		for (j=0; j<n-i-1; j++) {
			if (a[j] > a[j+1]) {
				x = a[j];
				a[j] = a[j+1];
				a[j+1] = x;
			}
		}
	}


	index = i;
	for (i=0; i<n; i++) {
		if (hd <= a[i]) {
			index = i;
			break;
		}
	}
	
	if (mov == 1) {
		tst = (size-hd) + (size-a[0]);
		printf("\nSequence is : ");
		for (i=index; i<n; i++)
			printf("%d\t", a[i]);
		for (i=index-1; i>=0; i--) 
			printf("%d", a[i]);

	} else {
		tst = (hd-a[0]) + (size-a[0]);
		printf("\nSequence is : ");
		for (i=index-1;i>=0;i--)
			printf("%d\t", a[i]);
		for (i=index; i<n; i++)
			printf("%d\t", a[i]);
	}
	
	printf("\nTotal seek time : %d ns", tst);
	
}

void cscan(int n, int a[], int hd) {
	int tst=0, i,j, x, mov, size, index;
	printf("Reading max buffer size... ");
	scanf("%d", &size);
	size--;
	
	printf("Reading the head movement direction... ");
	scanf("%d", &mov);

	//	sort
	for (i=0; i<n-1; i++) {
		for (j=0; j<n-i-1; j++) {
			if (a[j] > a[j+1]) {
				x = a[j];
				a[j] = a[j+1];
				a[j+1] = x;
			}
		}
	}

	//	setting index
	index = i;
	for (i=0; i<n; i++) {
		if (hd <= a[i]) {
			index = i;
			break;
		}
	}

	if (mov == 1) {
		tst = (size-hd) + (size-0) + (a[index-1]);
		printf("\nScheduled Sequence : ");
		for (i=index; i<n; i++) 
			printf("%d\t", a[i]);
		for (i=0; i<index-i; i++)
			printf("%d\t", a[i]);
	} else if (mov == 0) {
		tst = hd + size;
		printf("\nScheduled Sequence : ");
		for (i=index-1; i>=0; i--) 
			printf("%d\t",a[i]);
		for (i=index;i<n;i++)
			printf("%d\t", a[i]);
	}
	printf("\nTotal seek time = %d ns", tst);
}

void main() {
	int hd, n, r[100], i;
	printf("Reading the number of requests.... ");
	scanf("%d", &n);
	printf("Reading the request sequence... \n");
	for (i=0; i<n; i++)
		scanf("%d", &r[i]);

	printf("\nReading the current head position : ");
	scanf("%d", &hd);

	int opt;
	do {
		printf("\nDo what?! 1) FCFS 2) SCAN 3) CSCAN 4) EXIT\t");
		scanf("%d", &opt);

		switch (opt) {
			case 1:
				printf("\n---FCFS DISK SCHEDULING---\n");
				fcfs(n,r,hd);
				break;
			case 2:
				printf("\n---SCAN DISK SCHEDULING---\n");
				scan(n,r,hd);
				break;
			case 3:
				printf("\n---CSCAN DISK SCHEDULING---\n");
				cscan(n,r,hd);
				break;
			case 4:
				printf("\n---PROGRAM EXITED SUCCESSFULLY!---\n");
				break;
			default:
				printf("Invalid option. Try Again!\n");
				break;
		}
	} while (opt!=4);
}
