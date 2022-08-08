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

int bindCreatedSocket(int hSocket) 
{
    int iRetVal    = -1;
    int clientPort = 12345;

    struct sockaddr_in remote = {0};

    //Internet address family
    remote.sin_family = AF_INET;

    //Any incoming interface
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    // ocal port
    remote.sin_port = htons(clientPort);

    iRetVal = bind(hSocket, (struct sockaddr *)&remote, sizeof(remote));
    return iRetVal;
}

int main(int argc, char *argv[]) 
{
    int socket_desc = 0;
    int sock        = 0;
    int clientLen   = 0;

    struct sockaddr_in client;

    char client_message[200] = {0};
    char message[100]        = {0};

    //Create socket
    socket_desc = socketCreate();

    if (socket_desc == -1)  
    {
        printf("\nCould not create socket!");
        return 1;
    }

    printf("\nSocket created successfully");

    //Bind
    if(bindCreatedSocket(socket_desc) < 0) 
    {
        perror("\nBind failed!");
        return 1;
    }

    printf("\nBind successful");

    //Listen on 3 sockets
    listen(socket_desc, 3);

    printf("\nWaiting for incoming connections...\n");
    clientLen = sizeof(struct sockaddr_in);

    //Accept connection from an incoming client
    sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&clientLen);

    if (sock < 0)  
    {
       perror("\nConnection accept failed!");
       return 1;
    }

    printf("\nConnection accepted");
    memset(client_message, '\0', sizeof client_message);
    memset(message,        '\0', sizeof message);

    //Receive reply from client
    if(recv(sock, client_message, 200, 0) < 0) 
    {
        printf("\nMessage reception failed!");
    }

    printf("\nReceived message from Client: %s\n",client_message);

    int i = atoi(client_message);
    i--;
    sprintf(message, "%d", i);

    close(sock);

    printf("\nWaiting for incoming connections...");

    //Accept connection from an incoming client
    sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&clientLen);

    if (sock < 0)  
    {
       perror("\nSocket connection failed!");
       return 1;
    }

    printf("\nConnection successful");

    //Send some data
    if( send(sock, message, strlen(message), 0) < 0)  
    {
        printf("\nMessage transmission failed!");
        return 1;
    }

    return 0;
}
