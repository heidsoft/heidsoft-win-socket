#include "HeidSoftCommon.h"
#include <stdio.h>
#include <string.h>
CinitSock initSock;	//初始化Winsock库
int main()
{
	char szHost[256];
	//初始化char
	memset(szHost,0,sizeof(szHost));
	//取得本地主机名称
	::gethostname(szHost,sizeof(szHost));
	printf("本地主机名是：%s\n",szHost);
	//通过主机名得到地址信息
	hostent *pHost=::gethostbyname(szHost);
	//打印出所有ip地址
	in_addr addr;
	
	for(int i=0;;i++)
	{
		char *p=pHost->h_addr_list[i];//p指向一个32位的ip地址
		if(p==NULL)
			break;
		memcpy(&addr.S_un.S_addr,p,pHost->h_length);
		char *szIp=::inet_ntoa(addr);
		printf("本机IP地址字符表达形式是：%s \n",szIp);
		printf("本地IP地址整数表达形式是：%ld \n",::inet_addr(szIp));
	}
	
	return 0;
}
