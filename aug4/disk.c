#include<stdio.h>

void fcfs(int n, int a[], int head) {
	printf("---FIRST-COME-FIRST-SERVED!---\n");
	int totalSeekTime = 0, i , x;
	for (i=0;i<n;i++) {
		x = a[i] - head;
		if (x < 0)
			x = -x;
		totalSeekTime += x;
		head = a[i];
	}

	printf("\nThe Scheduled Sequence is : ");
	for (i=0; i<n; i++)
		printf("%d\t", a[i]);
	printf("\nThe total seek time = %d ms\n", totalSeekTime);
}

void cscan(int n, int a[], int head) {
	printf("---C-SCAN DISK SCHEDULING---\n");
	int totalSeekTime = 0, i,j,x,size, mov, temp, index;
	
	printf("\nEnter total disk size... ");
	scanf("%d", &size);
	size--;

	printf("Enter the head movement direction (0 for left, 1 for right)... ");
	scanf("%d", &mov);

	// bubble sorting
	for (i=0;i<n;i++) {
		for (j=0;j<n-i-1;j++) {
			if (a[j]> a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}

	index = i;

	for (i=0; i<n; i++) {
		if (head <= a[i]) {
			index = i;
			break;
		}
	}

	if (mov == 1) {
		totalSeekTime = (size-head)+(size-0)+(a[index-1]-0);
		printf("\nThe Scheduled Sequence : ");
		
		for (i=index; i<n; i++) 
			printf("%d\t", a[i]);
		for (i=0; i<index-1;i++) 
			printf("%d\t", a[i]);
		printf("\nThe total seek time = %d ms\n", totalSeekTime);
	} else {
		totalSeekTime = head+size;

		printf("\nThe Scheduled Sequence : ");

		for (i=index-1; i>=0; i--) 
			printf("%d\t", a[i]);
		for (i=index; i<n; i++) 
			printf("%d\t", a[i]);
		printf("\nThe total seek time = %d ms\n", totalSeekTime);
	}

}

void scan(int n, int a[], int head) {
	printf("\n---SCAN DISK SCHEDULING---\n");
	int totalSeekTime = 0, i, j, x, index, mov, temp, size;

	printf("\nEnter the total disk size : ");
	scanf("%d", &size);

	size--;

	printf("Enter the head movement direction (0 for left and 1 for right) ");
	scanf("%d", &mov);

	// sort
	for (i=0;i<n;i++) {
		for (j=0;j<n-i-1;j++) {
			if (a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}

	index = i;
	for (i=0; i<n;i++) {
		if (head <= a[i]) {
			index = i;
			break;	
		}
	}

	if (mov == 1) {
		totalSeekTime = (size-head) + (size-a[0]);
		printf("\nThe Scheduled Sequence is : ");
		for (i=index; i<n;i++)
			printf("%d\t", a[i]);
		for (i=index-1;i>=0;i--) 
			printf("%d\t", a[i]);
		printf("The total seek time : %d ms", totalSeekTime);
	} else {
		totalSeekTime = (head-a[0]) + (size-a[0]);
		printf("\n Scheduled sequence is : ");
		for (i=index-1;i>=0;i--) 
			printf("%d\t", a[i]);
		for (i=index;i<n;i++) 
			printf("%d\t", a[i]);
		printf("\nTotal seek time is %d\n", totalSeekTime);
	}
}


void main() {
	int requests[100], i, n, h;
	int opt;
	printf("Enter the number of requests... ");
	scanf("%d", &n);

	// reading the request sequence...
	printf("Reading the request sequence...\n");
	for (i=0; i<n; i++) 
		scanf("%d", &requests[i]);
	printf("---Requests read successfully!---\n");

	printf("Reading the head position... ");
	scanf("%d", &h);
	do {
		printf("\n~D i s k   S c h e d u l i n g~\n");
		printf("1) FCFS 2) SCAN 3) C-SCAN 4) exit	Enter choice: ");
		scanf("%d",&opt);
		switch (opt) {
			case 1:
				fcfs(n,requests,h);
				break;
			case 2: 
				scan(n,requests,h);
				break;
			case 3:
				cscan(n,requests,h);
				break;
			case 4:
				break;
			default:
				printf("Invalid choice try again!");
				break;
				
		}	
	}while (opt!=4);
}
