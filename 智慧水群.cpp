#include<windows.h>
#include<iostream>
#include<string>
using namespace std;
void qsend()
{
		keybd_event(17,0,0,0);
		keybd_event(86,0,0,0);
		keybd_event(17,0,KEYEVENTF_KEYUP,0);
		keybd_event(86,0,KEYEVENTF_KEYUP,0);
		keybd_event(13,0,0,0);
		keybd_event(13,0,KEYEVENTF_KEYUP,0);
		Sleep(50);	
}
BOOL StringToClipBoard(char* srcString) {
	BOOL bResult = FALSE;
	DWORD dwLength = strlen(srcString);
	HANDLE hGlobalMemory = GlobalAlloc(GHND, dwLength + 1); // 分配内存
	LPBYTE lpGlobalMemory = (LPBYTE)GlobalLock(hGlobalMemory); // 锁定内存
	if ( NULL != lpGlobalMemory ) {
		strcpy((char*)lpGlobalMemory, srcString);
		::GlobalUnlock(hGlobalMemory); // 锁定内存块解锁
		::OpenClipboard(NULL); // 打开剪贴板
		::EmptyClipboard(); // 清空剪贴板
		::SetClipboardData(CF_TEXT, hGlobalMemory); // 将内存中的数据放置到剪贴板
		::CloseClipboard();

		bResult = TRUE;
	}
	return bResult;
}
void sendn(string s)
{
	int x = stoi(s);
	for(int i=1;i<=x;++i)
	qsend();
}
int main()
{
	string s,buffer;
	while(cin >> s)
	{
		Sleep(3000);
		if(s.find("/sendn ")!=string::npos)
		{
			sendn(s.substr(7));
			continue;
		}
		for(int i=0;i<s.size();i+=2)
		{
			buffer = s.substr(i,2);
			StringToClipBoard(const_cast<char*>(buffer.c_str()));
			Sleep(50);
			qsend();
			Sleep(120);
		}
	}
	return 0;
}
