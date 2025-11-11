#include <stdio.h>

struct Process {
    int id, burst, remaining;
};

int main() {
    int n, quantum, finished=0, time=0, i;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    struct Process p[n];
    for(i=0;i<n;i++) {
        printf("P%d burst time: ", i+1);
        scanf("%d",&p[i].burst);
        p[i].id = i+1;
        p[i].remaining = p[i].burst;
    }
    printf("Enter Time Quantum: ");
    scanf("%d",&quantum);
    printf("Order: ");
    while(finished<n) {
        for(i=0;i<n;i++) {
            if(p[i].remaining > 0) {
                if(p[i].remaining <= quantum) {
                    time += p[i].remaining;
                    printf("P%d ", p[i].id);
                    p[i].remaining = 0; finished++;
                } else {
                    time += quantum;
                    printf("P%d ", p[i].id);
                    p[i].remaining -= quantum;
                }
            }
        }
    }
    printf("\n");
    return 0;
}

