#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sock;
    struct sockaddr_in server;
    char *message = "Hello Server";
    char server_reply[2000];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    connect(sock, (struct sockaddr *)&server, sizeof(server));

    send(sock, message, strlen(message), 0);
    recv(sock, server_reply, 2000, 0);

    printf("Server reply: %s\n", server_reply);

    close(sock);
    return 0;
}
