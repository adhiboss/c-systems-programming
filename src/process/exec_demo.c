#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before exec() - PID: %d\n", getpid());

    char *args[] = {"ls", "-l", NULL};

    execvp("ls", args);

    perror("execvp failed");
    return 1;
}
