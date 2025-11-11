#include <stdio.h>

struct Process {
    int id, arrival, burst, done;
};

int main() {
    int n, i, completed=0, time=0, min, sel, waiting=0, turnaround=0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    for(i=0;i<n;i++) {
        printf("P%d arrival time: ", i+1); scanf("%d",&p[i].arrival);
        printf("P%d burst time: ", i+1); scanf("%d",&p[i].burst);
        p[i].id = i+1; p[i].done = 0;
    }
    printf("Order: ");
    while(completed < n) {
        min=9999; sel=-1;
        for(i=0;i<n;i++)
            if(!p[i].done && p[i].arrival <= time && p[i].burst < min) {
                min = p[i].burst; sel = i;
            }
        if(sel==-1) {
            time++;
            continue;
        }
        printf("P%d ", p[sel].id);
        waiting += time - p[sel].arrival;
        time += p[sel].burst;
        turnaround += time - p[sel].arrival;
        p[sel].done = 1;
        completed++;
    }
    printf("\nAvg waiting: %.2f\n", (float)waiting/n);
    printf("Avg turnaround: %.2f\n", (float)turnaround/n);
    return 0;
}

