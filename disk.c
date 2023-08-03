#include<stdio.h>
void fcfs(int m, int a[], int hd);
void scan(int m, int a[], int hd);
void cscan(int m, int a[], int hd);

int main() { 
	int r[100], i, n, h;
	printf("\nEnter the number of requests: ");
	scanf("%d", &n);
	printf("\nEnter the requesting sequence: ");
	for (i = 0; i < n; i++)
		scanf("%d", &r[i]);
	printf("\nEnter the current head position: ");
	scanf("%d", &h);
	fcfs(n, r, h);
	scan(n, r, h);
	cscan(n, r, h);
	return 0;
}

void fcfs(int m, int a[], int hd){ printf("\nFIRST COME FIRST SERVED\n");
	int tst = 0, i, x;
	for (i = 0; i < m; i++) {
		x = a[i] - hd;
		if (x < 0)
			x = -x;
		tst = tst + x;
		hd = a[i];
	}
	printf("\nScheduled sequence is:\n");
	for (i = 0; i < m; i++)
		printf("%d\t", a[i]);
	printf("\nTotal seek time is %d.\n", tst);
}

void scan(int m, int a[], int hd) { 
	printf("\nSCAN...\n");
	int tst = 0, i, j, x, size, mov, temp, index;
	printf("\nEnter the total disk size: ");
	scanf("%d", &size);
	size = size - 1;
	printf("\nEnter the head movement direction (1 for high, 0 for low): ");
	scanf("%d", &mov);
	for (i = 0; i < m - 1; i++) {
		for (j = 0; j < m - i - 1; j++) {
			if (a[j] > a[j + 1]) { 
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	index = i;
	for (i = 0; i < m; i++) {
		if (hd <= a[i]) {
			index = i;
			break;
		}
	}
	if (mov == 1) { 
		tst = (size - hd) + (size - a[0]);
		printf("\nScheduled sequence is:\n");
		for (i = index; i < m; i++)
			printf("%d\t", a[i]);
		for (i = index - 1; i >= 0; i--)
			printf("%d\t", a[i]);
		printf("\nTotal seek time is %d.\n", tst);
	} else { 
		tst = (hd - a[0]) + (size - a[0]);
		printf("\nScheduled sequence is:\n");
		for (i = index - 1; i >= 0; i--)
			printf("%d\t", a[i]);
		for (i = index; i < m; i++)
			printf("%d\t", a[i]);
		printf("\nTotal seek time is %d.\n", tst);
	}
}

void cscan(int m, int a[], int hd) { 
	printf("\nC-SCAN\n");
	int tst = 0, i, j, x, size, mov, temp, index;
	printf("\nEnter the total disk size: ");
	scanf("%d", &size);
	size = size - 1;
	printf("\nEnter the head movement direction (1 for high, 0 for low): ");
	scanf("%d", &mov);
	for (i = 0; i < m - 1; i++) {
		for (j = 0; j < m - i - 1; j++) {
			if (a[j] > a[j + 1]){ 
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	index = i;
	for (i = 0; i < m; i++) {
		if (hd <= a[i]) {
			index = i;
			break;
		}
	}
	if (mov == 1) { 
		tst = (size - hd) + (size - 0) + (a[index - 1] - 0);
		printf("\nScheduled sequence is:\n");
		for (i = index; i < m; i++)
			printf("%d\t", a[i]);
		for (i = 0; i < index - 1; i++)
			printf("%d\t", a[i]);
		printf("\nTotal seek time is %d.\n", tst);
	} else { 
		tst = hd + size;
		printf("\nScheduled sequence is:\n");
		for (i = index - 1; i >= 0; i--)
			printf("%d\t", a[i]);
		for (i = index; i < m; i++)
			printf("%d\t", a[i]);
		printf("\nTotal seek time is %d.\n", tst);
	}
}
