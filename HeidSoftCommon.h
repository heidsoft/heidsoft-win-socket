#include <WinSock2.h>
#pragma comment(lib,"WS2_32")

class CinitSock
{
public:
	CinitSock(BYTE minorVer=2,BYTE majorVer=2)
	{
		//初始化WS2_32.DLL
		WSADATA wsaData;
		WORD sockVersion=MAKEWORD(minorVer,majorVer);
		if(::WSAStartup(sockVersion,&wsaData)!=0)
		{
			exit(0);
		}
	}
	~CinitSock()
	{
		::WSACleanup();
	}
};
