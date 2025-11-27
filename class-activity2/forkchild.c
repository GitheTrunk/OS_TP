#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   // fork(), execlp()
#include <sys/wait.h> // wait()

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        exit(1);
    } 
    else if (pid == 0) {
        // Child process
        printf("Child process running ls command...\n");

        // Use exec to run ls
        execlp("ls", "ls", NULL);

        // If exec fails:
        perror("execlp failed");
        exit(1);
    } 
    else {
        // Parent process
        printf("Parent: waiting for child...\n");
        wait(NULL);
        printf("Parent: child finished.\n");
    }

    return 0;
}
