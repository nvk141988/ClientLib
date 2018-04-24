
//FileName : TestClientLib.cpp

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "ClientSocket.h"
using namespace std;

#define  PORT		(80)

int main(void)
{
    int ret;
	char data[] = "Data from Client";
	char rcvdBuffer[100] = {0};
    ClientSocket AppSocket(PORT, "google.com");
    cout << "Starting CLient" << endl;
    AppSocket.createTCPSocket();
    AppSocket.connectToServer();
    AppSocket.sendDataToServer(data, strlen(data));
    AppSocket.getDataFromServer(rcvdBuffer, 100);
}
    
