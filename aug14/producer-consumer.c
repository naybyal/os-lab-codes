#include<stdio.h>
#include<stdlib.h>

int mutex = 1, full = 0, empty = 5, x = 0;

void producer() {
	--mutex;
	++full;
	--empty;
	++x;
	printf("\nProducer produces %d", x);
	++mutex;
}

void consumer() {
	--mutex;
	--full;
	++empty;
	printf("\nConsumer consumes %d", x);
	--x;
	++mutex;
}

void main() {
	int n,i;
	printf("Buffer size = 5\n");
	printf("Options : 1) Producer 2) Consumer 3) EXIT\t");
	int opt;
	do {
		printf("\nEnter option  : ");
		scanf("%d", &opt);
		switch (opt) {
			case 1:
				if (mutex==1 && empty!=0)	producer();
				else	printf("Buffer is full");
				break;
			case 2:
				if (mutex==1 && full!=0)	consumer();
				else printf("Buffer is empty");
				break;
			case 3:
				break;
			default:
				printf("Invalid option");
				break;
		}
	} while (opt!=3);
}
