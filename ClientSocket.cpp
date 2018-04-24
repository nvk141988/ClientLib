//File Name: ClientSocket.cpp

#include "ClientSocket.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

using namespace std;

ClientSocket::ClientSocket(int port, std::string ip_address)
{
        this->portno = port;
        this->ip_address = ip_address;
	this->socketid = -1;
}

int ClientSocket::createTCPSocket()
{
	socketid = socket(AF_INET, SOCK_STREAM, 0);
	if(socketid == -1)
	{
		cout <<  "Socket Creation Failed !!" << endl; 
		return(-1);
	}    
    return(1);
}
int ClientSocket::connectToServer()
{
    int ret;
	memset(&serverAddr,0,sizeof(serverAddr));
	serverAddr.sin_family =	AF_INET;
	serverAddr.sin_port = htons(portno); //Save in network byte order
	hp = gethostbyname(ip_address.data());
	if(hp == NULL)
	{
		cout << "Getting Host Name Failed!!" << endl;
		return(-1);
	}

	memmove((char*)hp->h_addr,(char*)&serverAddr.sin_addr,hp->h_length);
	ret = connect(socketid, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0)
	{
		cout << endl << "Connection Failed!!" << endl;
		return(-1);
	}
    return(1);
}

int ClientSocket::sendDataToServer(const char * data, int dataLen)
{
    int ret;
    ret = write(socketid,(void*)data, dataLen);
    if(ret < 0)
    {
        cout << "Write To Server Failed" << endl;
        return(-1);
    }
	cout << "Message Sent!!" << endl;
    return(1);
}

int ClientSocket::getDataFromServer(const char * buffer, int readLen)
{
    int ret;
	ret = read(socketid,(void*)buffer, readLen);
	if(ret < 0)
	{
		cout << "Error Reading from Server" << endl;
		return(-1);
	}
	cout << buffer << endl;    
    return(1);
}
