#include <stdio.h>

#define N 10

struct Process {
    int id, arrival, burst, priority, remaining;
};

int main() {
    int n, time=0, completed=0, min, sel, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[N];
    for(i=0;i<n;i++) {
        printf("P%d arrival time: ", i+1); scanf("%d", &p[i].arrival);
        printf("P%d burst time: ", i+1); scanf("%d", &p[i].burst);
        printf("P%d priority: ", i+1); scanf("%d", &p[i].priority);
        p[i].remaining = p[i].burst;
        p[i].id = i+1;
    }
    printf("Order of execution: ");
    while(completed<n) {
        min = 9999;
        sel = -1;
        for(i=0;i<n;i++)
            if(p[i].arrival <= time && p[i].remaining > 0 && p[i].priority < min) {
                min = p[i].priority; sel = i;
            }
        if(sel!=-1) {
            printf("P%d ", p[sel].id);
            p[sel].remaining--;
            time++;
            if(p[sel].remaining==0) completed++;
        } else time++;
    }
    printf("\n");
    return 0;
}

