/*  Networking Exercise
 *
 *  simple client setup to demonstrate networking capabilities
 * 
 *  Author: Jaryd Peters
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

//Create socket for server communication
short socketCreate(void)
{
    printf"\nCreating socket...");
    short hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

//Attempt server connection
int socketConnect(int hSocket)
{
    int iRetVal    = -1;
    int serverPort = 12345;

    struct sockaddr_in remote = {0};

    //Address of local host
    remote.sin_addr.s_addr = inet_addr("127.0.0.1");
    remote.sin_family      = AF_INET;
    remote.sin_port        = htons(serverPort);

    iRetVal = connect(hSocket, (struct sockaddr*)&remote, sizeof(struct sockaddr_in));

    return iRetVal;
}

//Send data to server and set 20 second timeout
int socketSend(int hSocket, char* rqst, short lenRqst)
{
    int shortRetVal = -1;
    
    struct timeval tv;
    //20 second timeout
    tv.tv_sec  = 20;
    tv.tv_usec = 0;

    if(setsockopt(hSocket, SOL_SOCKET,SO_SNDTIMEO, (char *)&tv, (sizeof(tv)) < 0)) 
    {
        printf("\nTime Out!");
        return -1;
    }

    shortRetVal = send(hSocket, rqst, lenRqst, 0);
    return shortRetVal;
}

int main(int argc, char* arv[])
{
    int hSocket = 0;

    char sendToServer[100] = {0};

    //Create socket
    hSocket = socketCreate();

    if(hSocket == -1)   
    {
        printf("\nCould not create socket!");
        return 1;
    }

    printf("\nSocket created successfully");

    //Connect to remote server
    if (socketConnect(hSocket) < 0) 
    {
        perror("\nConnection failed!");
        return 1;
    }

    printf("\nConnection with server successful");
    printf("\nEnter the Message: ");
    fgets(sendToServer, 100, stdin);

    //Send data to server
    socketSend(hSocket, sendToServer, strlen(sendToServer));

    close(hSocket);
    return 0;
}