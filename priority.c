/*
 * 	Program	->	Priority CPU Scheduling Algorithm
 * 	Author	->	rosettastoned12
 * */

#include<stdio.h>

struct process {
        /*
         *      TAT     ->      Turn Around Time
         *      WT      ->      Waiting Time
         *      BT      ->      Burst Time
	 *      PRIO	->	Priority
         */
        int tat, wt, bt, id, prio;
}p[10], temp;

int main() {
	int i, j, numberOfProcesses;

        int total_TAT = 0, total_WT = 0;

        printf("Reading the number of processes... ");
        scanf("%d", &numberOfProcesses);

        // Initializing the Waiting Time of first process to 0
        p[0].wt = 0;

        printf("Reading the Burst Times of each process... \n");
        for(i=0; i<numberOfProcesses; i++) {
		printf("Process %d\t->\t", i+1);
                scanf("%d", &p[i].bt);
                p[i].id = i + 1;
        }

	printf("Reading the priority (lesser magnitude -> higher priority)\n");
	for (i=0; i<numberOfProcesses; i++) {
		printf("Process %d\t->\t", i+1);
		scanf("%d", &p[i].prio);

	}
        // Sorting the process by priority
        for (i=0; i<numberOfProcesses; i++) {
                for (j=0; j<numberOfProcesses-i-1; j++) {
                        if (p[j].prio > p[j+1].prio) {
                                temp = p[j];
                                p[j] = p[j+1];
                                p[j+1] = temp;
                        }
                }
        }

        /*
         * Waiting Time of each process is
         * the sum of Burst Time and Waiting Time
         * of the previous process
         */
        for (i=1; i<numberOfProcesses; i++) {
                p[i].wt = p[i-1].wt + p[i-1].bt;
                total_WT += p[i].wt;
        }

	/*
         * Turn Arount Time of each process is
         * the sum of Waiting Time and Burst Time
         * of the current process
         * */
        for (i=0; i<numberOfProcesses; i++) {
                p[i].tat = p[i].bt + p[i].wt;
                total_TAT += p[i].tat;
        }

        // Displaying the process, BT, WT and TAT as a table
        printf("\nPROCESS\tBT\tWT\tTAT");
        for (i=0; i<numberOfProcesses; i++) {
                printf("\nP%d\t%d\t%d\t%d", p[i].id, p[i].bt, p[i].wt, p[i].tat);
        }
        printf("\n");

        // Average Time = Total Time / Number of Processes
        float avg_TAT = (float)total_TAT / numberOfProcesses;
        float avg_WT = (float)total_WT / numberOfProcesses;
        printf("\nAverage TAT\t->\t%.1fms", avg_TAT);
        printf("\nAverage WT \t->\t%.1fms", avg_WT);
        printf("\n\n");

        //Displaying GANTT Chart
        printf("----GANTT Chart----\n");
        for (i=0; i<numberOfProcesses; i++)
                printf("| \tP%d \t", p[i].id);
        printf("|\n");
        printf("0\t");
        for (i=0; i<numberOfProcesses; i++)
                printf("\t%d\t", p[i].tat);
        printf("\n");

        printf("\n---LEGEND---\nBT  -> Burst Time\nWT  -> Waiting Time\nTAT -> Turn Around Time");
        printf("\n------------\n");
        return 0;
}
