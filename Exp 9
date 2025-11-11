#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main() {
    
    key_t key = ftok("shmfile", 65);

   
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *str = (char*) shmat(shmid, NULL, 0);

    if (fork() == 0) {
        
        sprintf(str, "Hello from child process!");
        printf("Child: Data written in memory: %s\n", str);
    } else {
        
        sleep(1);
        printf("Parent: Data read from memory: %s\n", str);
       
        shmdt(str);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}
