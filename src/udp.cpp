#include "udp.h"

Udp_client::Udp_client(const char* inetaddr, u_short port)
{
	_clientsocket = socket(AF_INET, SOCK_DGRAM, 0);
	_addr = { 0 };
	_addr.sin_family = AF_INET;
	_addr.sin_addr.s_addr = inet_addr(inetaddr);
	_addr.sin_port = htons(port);
	_client_len = sizeof(struct sockaddr);
}

Udp_client::~Udp_client()
{
	close(_clientsocket);
}

void Udp_client::send(const char* data, size_t datalen)
{
	int result = sendto(_clientsocket, data, datalen, 0, (struct sockaddr*)&_addr, _client_len);
	if(result > 0) cout << "[UDP SEND INFO] udp send msg bytes:" << result << endl;
	if(result == -1) cout << "[UDPSEND FAIL INFO] Udp send msg failed!" << endl;
}

Udp_server::Udp_server(const char* inetaddr, u_short port)
{
	_serversocket = socket(AF_INET, SOCK_DGRAM, 0);
	_addr = { 0 };
        _addr.sin_family = AF_INET;
        _addr.sin_addr.s_addr = inet_addr(inetaddr);
        _addr.sin_port = htons(port);
	_server_len = sizeof(struct sockaddr);
	int bindres = bind(_serversocket, (struct sockaddr*)&_addr, _server_len);
	if(bindres < 0) cout << "[UDPSERVERBIND FAIL INFO] Udp socket bind failed!" << endl;
}

Udp_server::~Udp_server()
{
	close(_serversocket);
}

string Udp_server::recive(int bufsize)
{
	char buf[bufsize];
	int result = recvfrom(_serversocket, buf, bufsize, 0, (struct sockaddr*)&_addr, &_server_len);
	if(result == -1) cout << "[UDPRECIVE FAIL INFO] Udp recive msg failed!" << endl;
	return (string)buf;
}
