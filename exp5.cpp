#include <stdio.h>

struct Process {
    int id, burst, priority;
};

int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n], temp;

 
    for(i = 0; i < n; i++) {
        printf("Process %d burst time: ", i + 1);
        scanf("%d", &p[i].burst);
        printf("Process %d priority (lower=high): ", i + 1);
        scanf("%d", &p[i].priority);
        p[i].id = i + 1;
    }
    
    for(i = 0; i < n-1; i++)
        for(j = i + 1; j < n; j++)
            if(p[j].priority < p[i].priority) {
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
    int time = 0;
    printf("Execution order: ");
    for(i = 0; i < n; i++) {
        printf("P%d ", p[i].id);
        time += p[i].burst;
    }
    printf("\n");
    return 0;
}

