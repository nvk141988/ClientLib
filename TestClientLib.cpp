
//FileName : TestClientLib.cpp

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "ClientSocket.h"
using namespace std;

#define  PORT		(54321)

int main(void)
{
    int ret;
	char data[] = "Data from Client";
	char rcvdBuffer[100] = {0};
    ClientSocket AppSocket(PORT, "192.168.8.1");
    cout << "Starting CLient" << endl;
    AppSocket.createTCPSocket();
    AppSocket.connectToServer();
    AppSocket.sendDataToServer(data, strlen(data));
    AppSocket.getDataFromServer(rcvdBuffer, 100);
}
    
