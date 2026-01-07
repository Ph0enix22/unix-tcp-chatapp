// client.c - connects to server, two-way chat
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sock_fd;
    struct sockaddr_in addr;
    char buf[1024];

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

    connect(sock_fd, (struct sockaddr*)&addr, sizeof(addr));
    printf("Connected to server.
");

    while (1) {
        // send message to server
        printf("You: ");
        if (!fgets(buf, sizeof(buf), stdin)) break;
        write(sock_fd, buf, strlen(buf));

        // read reply
        int n = read(sock_fd, buf, sizeof(buf) - 1);
        if (n <= 0) break;
        buf[n] = '';
        printf("Server: %s", buf);
    }

    close(sock_fd);
    return 0;
}
