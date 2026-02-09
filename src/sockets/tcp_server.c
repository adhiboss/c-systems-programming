#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 9090
#define BUF_SIZE 1024

int main() {
    int server_fd, client_fd;
    struct sockaddr_in addr;
    char buffer[BUF_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&addr, sizeof(addr));
    listen(server_fd, 5);

    printf("Server listening on port %d...\n", PORT);

    client_fd = accept(server_fd, NULL, NULL);

    int n = read(client_fd, buffer, BUF_SIZE - 1);
    buffer[n] = '\0';

    printf("Client says: %s\n", buffer);

    char *reply = "Message received by server!";
    write(client_fd, reply, strlen(reply));

    close(client_fd);
    close(server_fd);

    return 0;
}
