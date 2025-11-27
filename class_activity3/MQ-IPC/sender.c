// sender.c (System V)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include "common.h"

struct msgbuffer {
    long mtype;
    char mtext[MAX_SIZE];
};

int main() {
    int msgid;
    struct msgbuffer msg;

    // Create the message queue
    msgid = msgget(QUEUE_KEY, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // Prepare the message
    msg.mtype = 1;
    strcpy(msg.mtext, "Hello from sender!");

    // Send the message
    if (msgsnd(msgid, &msg, strlen(msg.mtext) + 1, 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    printf("Sender: Message sent.\n");

    return 0;
}
