#ifndef CLIENTNVK_H_
#define CLIENTNVK_H_

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
class ClientSocket
{
    private:
        int socketid;
        struct sockaddr_in  serverAddr;
        struct hostent *hp;
        int portno;
        std::string ip_address;
        
    public:
        ClientSocket(int port, std::string ip_address);
        int createTCPSocket();
        int connectToServer();
        int sendDataToServer(const char* data, int dataLen);
        int getDataFromServer(const char* buffer, int readLen);
	int closeConnection();
};



#endif
