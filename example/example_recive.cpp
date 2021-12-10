#include "../src/udp.h"

int main()
{
	Udp_server* us = new Udp_server("xxx.xxx.x.xxx", 1315);
	while(true)
	{
		cout << "[UDPRECIVE MSG] " << us->recive(1) << endl;
	}
	delete us;
	return 0;
}
