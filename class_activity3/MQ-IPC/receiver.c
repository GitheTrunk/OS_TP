// receiver.c (System V)
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

    // Connect to (or create) the message queue
    msgid = msgget(QUEUE_KEY, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // Receive message of type 1
    if (msgrcv(msgid, &msg, sizeof(msg.mtext), 1, 0) == -1) {
        perror("msgrcv");
        exit(EXIT_FAILURE);
    }

    printf("Receiver: Message received: %s\n", msg.mtext);

    // Remove the queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
    }

    return 0;
}
