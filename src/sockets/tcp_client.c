#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 9090
#define BUF_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in server;
    char buffer[BUF_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    connect(sock, (struct sockaddr *)&server, sizeof(server));

    char *msg = "Hello from TCP client!";
    write(sock, msg, strlen(msg));

    int n = read(sock, buffer, BUF_SIZE - 1);
    buffer[n] = '\0';

    printf("Server replied: %s\n", buffer);

    close(sock);
    return 0;
}
