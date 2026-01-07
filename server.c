// server.c - single client, two-way chat
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int server_fd, client_fd;
    struct sockaddr_in addr;
    char buf[1024];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 1);

    printf("Server waiting on port 8080...
");
    client_fd = accept(server_fd, NULL, NULL);
    printf("Client connected.
");

    while (1) {
        // read from client
        int n = read(client_fd, buf, sizeof(buf) - 1);
        if (n <= 0) break;
        buf[n] = '';
        printf("Client: %s", buf);

        // get reply from server user
        printf("You: ");
        if (!fgets(buf, sizeof(buf), stdin)) break;
        write(client_fd, buf, strlen(buf));
    }

    close(client_fd);
    close(server_fd);
    return 0;
}
