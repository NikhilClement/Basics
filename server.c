#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <errno.h>
#define PORT 3800
int main()
{
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int sockfd, newsockfd, ret;
    char rbuffer[1024];
    char sbuffer[] = "Hello there!";
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        printf("Socket creation error\n");
        exit(1);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if((bind(sockfd, (struct sockaddr*)&address, sizeof(address))) < 0)
    {
        printf("Binding error\n");
        exit(2);
    }
    listen(sockfd, 3);
    if((newsockfd = accept(sockfd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0)
    {
        printf("Accept Error\n");
        exit(3);
    }
    ret = recv(newsockfd, rbuffer, strlen(rbuffer), 0);
    if(ret == -1)
    {
        perror("");
    }
    printf("Received: %s\n, %d bytes", rbuffer, ret);
    ret = send(newsockfd, sbuffer, strlen(sbuffer), 0);
    if(ret == -1)
    {
        perror("");
    }
    return 0;
}
