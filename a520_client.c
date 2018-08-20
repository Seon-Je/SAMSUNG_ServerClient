/****************************************************************************
*
* Copyright 2018 Primesoft All Rights Reserved.
*
* Filename: 541_SocketClient.c
* Author: enj.park, yr.kim
* Release date: 2018/05/02
* Version: 2.0
*
****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

#include <sys/types.h>
#include <sys/wait.h>

#define MAXDATASIZE 100


int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("usage : ./program serverIP PORT");
        return -1;
    }

	int PORT = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in their_addr;
    memset(&their_addr, 0, sizeof(their_addr));
    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(PORT);
	inet_aton(argv[1], (struct in_addr*) &their_addr.sin_addr.s_addr);


    if (connect(sockfd, (struct sockaddr*) &their_addr, sizeof(their_addr)) == -1)
    {
        printf("connect error\n");
        return -1;
    }

    else
    {
        int recv_datasize, send_datasize;
        char send_data[MAXDATASIZE];
        char recv_data[MAXDATASIZE];

        while (1)
        {
            printf("Send message to Server: ");

            fgets(send_data,MAXDATASIZE,stdin);

            send(sockfd, send_data, strlen(send_data), 0);

//            recv_datasize = recv(sockfd, recv_data, MAXDATASIZE, 0);
//            recv_data[recv_datasize] = '\0';

//            printf("Received Message(%d bytes) : %s", recv_datasize, recv_data);

        }
    }

    close(sockfd);

    return 0;
}

