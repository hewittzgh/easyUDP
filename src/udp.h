#ifndef __UDP_H__
#define __UDP_H__

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

class Udp_client
{
private:
	int _clientsocket;
	struct sockaddr_in _addr;
	socklen_t _client_len;

public:
	Udp_client(const char* inetaddr, u_short port);
	~Udp_client();
	void send(const char* data, size_t datalen);
};

class Udp_server
{
private:
	int _serversocket;
	struct sockaddr_in _addr;
	socklen_t _server_len;
public:
	Udp_server(const char* inetaddr, u_short port);
	~Udp_server();
	string recive(int bufsize);
};

#endif
