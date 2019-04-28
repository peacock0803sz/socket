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
    struct sockaddr_in server;
    int sockfd;
    int n;
    char buffer[32];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(22);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Check connection
    if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) > 0 ){
        perror("Connect error!");
    }

    // Read data
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    printf("%d, %s\n", n, buffer);

    close(sockfd);

    return 0;
}
