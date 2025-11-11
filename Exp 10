#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MAX 100

struct msg_buffer {
    long msg_type;
    char msg_text[MAX];
} message;

int main() {
    key_t key;
    int msgid;

    key = ftok("progfile", 65);

    msgid = msgget(key, 0666 | IPC_CREAT);
    message.msg_type = 1;

    if (fork() == 0) {
   
        printf("Child: Enter a message: ");
        fgets(message.msg_text, MAX, stdin);
        msgsnd(msgid, &message, sizeof(message), 0);
        printf("Child: Message sent!\n");
    } else {
        
        sleep(1);
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        printf("Parent: Message received: %s\n", message.msg_text);
         msgctl(msgid, IPC_RMID, NULL);
    }

    return 0;
}

      

