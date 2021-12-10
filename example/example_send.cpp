#include "../src/udp.h"
#include <string.h>
int main()
{
	Udp_client* uc = new Udp_client("xxx.xxx.x.xxx", 1314);
	string msg = "xxxxxx";
	const char *sendmsg = msg.c_str();
	while(true)
	{
		sleep(3);	
		uc->send(sendmsg, strlen(sendmsg));
	}
	delete uc;
	return 0;
}
