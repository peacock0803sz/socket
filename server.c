//
// Created by peacock on 19/04/28.
//
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
    int sockfd;
    struct sockaddr_in addr;
    struct sockaddr_in client;
    int len;
    int sock;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(22);
    addr.sin_addr.s_addr = INADDR_ANY;
    bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));

    // Wait for a connection
    listen(sockfd, 5);

    // Accept connection
    len = sizeof(client);
    sock = accept(sockfd, (struct sockaddr *)&client, &len);

    // Send
    write(sock, "HELLO!", 5);

    close(sock);
    close(sockfd);

    return 0;
}
