#include <stdio.h>
#include <limits.h>

typedef struct {
    int pid;
    int burstTime;
    int waitingTime;
    int turnAroundTime;
} Process;

void sortByBurstTime(Process proc[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].burstTime > proc[j].burstTime) {
                Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

void findWaitingTime(Process proc[], int n) {
    proc[0].waitingTime = 0;
    for (int i = 1; i < n; i++) {
        proc[i].waitingTime = proc[i - 1].waitingTime + proc[i - 1].burstTime;
    }
}

void findTurnAroundTime(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnAroundTime = proc[i].burstTime + proc[i].waitingTime;
    }
}

void findAvgTime(Process proc[], int n) {
    int totalWaitingTime = 0, totalTurnAroundTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += proc[i].waitingTime;
        totalTurnAroundTime += proc[i].turnAroundTime;
    }
    printf("Average waiting time: %.2f\n", (float)totalWaitingTime / n);
    printf("Average turnaround time: %.2f\n", (float)totalTurnAroundTime / n);
}

int main() {
    Process proc[] = {
        {1, 6, 0, 0},
        {2, 8, 0, 0},
        {3, 7, 0, 0},
        {4, 3, 0, 0}
    };
    int n = sizeof(proc) / sizeof(proc[0]);

    sortByBurstTime(proc, n);
    findWaitingTime(proc, n);
    findTurnAroundTime(proc, n);
    findAvgTime(proc, n);

    return 0;
}

