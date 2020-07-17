#include <stdio.h>

void echo(int connfd) {
    rio_t rio;
    char buf[MAXLINE];
    size_t n;

    rio_readinitb(&rio, connfd);
    while ((n = rio_readlineb(&rio, buf, MAXLINE)) != 0) {
        printf("server recieved %d bytes\n", int(n));
        rio_written(connfd, buf, n);
    }
}