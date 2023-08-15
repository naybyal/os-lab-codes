#include<stdio.h>

void fcfs (int n, int a[], int hd) {
	int tst = 0, i, x;
	for (i=0; i<n; i++) {
		x = a[i] - hd;
		if (x<0)
			x = -x;
		tst += x;
		hd = a[i];
	}

	printf("\nScheduled sequence : ");
	for (i=0; i<n; i++)
		printf("%d\t", a[i]);
	printf("\nTotal seek time = %d ns\n\n", tst);
}


void scan (int n, int a[], int hd) {

	int tst=0, i, j, x,size, mov, temp, index;

	printf("\nEnter the total disk size : ");
	scanf("%d", &size);
	size--;

	printf("\nEnter the head movement direction (1 for high, 0 for low) : ");
	scanf("%d", &mov);

	for (i=0; i<n-1; i++) {
		for (j=0; j<n-i-1; j++) {
			if (a[j] > a[j+1]) {
				temp = a[j]; 
				a[j] = a[j+1];
				a[j+1] = temp;
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
		tst = (size-hd)+(size-a[0]);
		printf("\nScheduled sequence : ");

		for (i=index; i<n; i++) 
			printf("%d\t", a[i]);
		for (i=index-1; i>=0; i--)
			printf("%d\t", a[i]);
	} else {
		tst = (hd-a[0]) + (size-a[0]);
		printf("\nScheduled sequence : ");
		for (i=index-1; i>=0; i--) 
			printf("%d\t", a[i]);
		for (i=index; i<n; i++)
			printf("%d\t", a[i]);
	}

	printf("\nTotal seek time = %d ns\n\t", tst);

}


void cscan (int n, int a[], int hd) {

	int tst=0, i,j,x, size, mov, temp, index;
	printf("\nEnter the total disk size... ");
	scanf("%d", &size);

	size--;

	printf("Enter the head movement direction (1 for high, 0 for low) : ");
	scanf("%d", mov);

	for (i=0; i<n-1; i++) {
		for (j=0; j<n-i-1; j++) {
			if ()
		}
	}

}

void main() {
	int r[100], i, n, hd;

	printf("Reading the number of requests : ");
	scanf("%d", &n);

	printf("\nReading request sequence... \n");
	for (i=0; i<n; i++)
		scanf("%d", &r[i]);

	printf("\nReading the current head position : ");
	scanf("%d", &hd);
	
	int opt;
	
	do {
		printf("\nDo? 1) FCFS 2) SCAN 3) CSCAN 4) EXIT\t->\t");
		scanf("%d", &opt);

		switch (opt) {
			case 1:
				printf("\n\n----FCFS DISK SCHEDULING----\n\n");
				fcfs(n,r,hd);
				break;
			case 2:
				printf("\n\n----SCAN DISK SCHEDULING----\n\n");
				//scan(n,r,hd);
				break;	
			case 3:
				printf("\n\n----CSCAN DISK SCHEDULING----\n\n");
				//cscan(n,r,hd);
				break;
			case 4:
				printf("\n---PROGRAM EXITED SUCCESSFULLY!---\n\n");
				break;
			default:
				printf("\nINVALID OPTION... TRY AGAIN!\n");
				break;
		}

	} while (opt!=4);
}
