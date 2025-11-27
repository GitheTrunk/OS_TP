#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) {
        printf("Child: launching Windows mspaint.exe...\n");

        // Try default Windows path
        execlp("/mnt/c/Windows/System32/mspaint.exe", "mspaint.exe", NULL);

        // If failed, try WSL resolve (calling mspaint.exe directly)
        execlp("mspaint.exe", "mspaint.exe", NULL);

        perror("exec failed");
        exit(1);
    }
    else {
        printf("Parent: waiting for child...\n");
        wait(NULL);
        printf("Parent: child finished.\n");
    }

    return 0;
}
