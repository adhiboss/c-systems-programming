#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char buffer[100];

    fd = open("demo.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    char *msg = "Hello from file descriptors!\n";
    write(fd, msg, strlen(msg));
    close(fd);

    fd = open("demo.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    int bytes = read(fd, buffer, sizeof(buffer) - 1);
    buffer[bytes] = '\0';

    printf("Read from file: %s", buffer);
    close(fd);

    return 0;
}
