#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("Child process running!\n");
        printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
    } else {
        printf("Parent process running!\n");
        printf("Parent PID: %d, Child PID: %d\n", getpid(), pid);
        wait(NULL);
        printf("Child finished. Parent exiting.\n");
    }

    return 0;
}
