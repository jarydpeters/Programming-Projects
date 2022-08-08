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

//Receive the data from the server
int socketReceive(int hSocket,char* rsp,short RvcSize) 
{
    int shortRetVal = -1;
    struct timeval tv;
    //20 second timeout
    tv.tv_sec  = 20;
    tv.tv_usec = 0;

    if(setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO, (char*)&tv, (sizeof(tv)) < 0))
    {
        printf("\nTime Out!");
        return -1;
    }

    shortRetVal = recv(hSocket, rsp, RvcSize, 0);
    printf("\nResponse: %s\n",rsp);
    return shortRetVal;
}

int main(int argc, char *argv[])  
{
    int hSocket = 0, read_size = 0;

    char server_reply[200] = {0};

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

    //Received data from server
    read_size = socketReceive(hSocket, server_reply, 200);
    printf("Server Response : %s: read_size %d\n\n", server_reply, read_size);
    
    close(hSocket);
    return 0;
}
