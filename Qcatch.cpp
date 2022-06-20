#define NDEBUG

#include<Windows.h>
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<cstring>
#include<assert.h>
#include<wchar.h>
#include<tchar.h>
#include<fstream>
#include<cstddef>
#include<vector>
#include<sstream>
#include<stdlib.h>
#include<locale.h>

#define kdown(x) keybd_event(x,0,0,0);
#define kup(x) keybd_event(x,0,KEYEVENTF_KEYUP,0);
#define mdown mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
#define mup mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
#define mrdown mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
#define mrup mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
#define S(x) Sleep(x);
#define UWnd(x) SetWindowPos(x,NULL,0,0,0,0,1);
#define QWnd SetWindowPos(Qwd,NULL,0,0,0,0,1);

using namespace std;

#define OUTDATA
typedef unsigned int QInfType;

inline void mgo(POINT P)
{
	SetCursorPos(P.x,P.y);
}
float getSysVersion();	//windows-version(such as windows 10.0)
void throwQFile();
void QWrite();
wchar_t* getCBoard();
void writeCBoard();
BOOL StringToClipBoard(wchar_t* srcString);
HWND qHWND();
void getinf();
void allcat();
void prefun();
void qsend(wchar_t* ch);
void stick();
void ent();
void tdata();
void uptdata();
void sget();
void cat();
void qmessage();
wchar_t* AnsiToUnicode( const char* szStr );

const HWND Qwd = (HWND)0x3021a;
const char* name = "Minecraft Lepton Sever （几乎不含mc元素）";
POINT Qset;
LPPOINT pQset = &Qset;
HWND Qwnd;
const char* fname = "C:\\Users\\21983\\Desktop\\QQrob\\inf.txt";
wofstream ofile(fname);
wstring prewrite;
POINT getting = {941,843};
POINT sending = {928,981};
POINT shortGet = {944,852};
POINT catByPoint = {990,872};
wstring lqdata;
vector<string> qdata;
wstring lsdata;
wstring dat;
wstring ldat;
bool doflag = false;
const int tire = 10;
int times = tire;
wchar_t* eANSI = L"Undefined ANSI Code";
wchar_t* bus;
unsigned int done;
wchar_t* ch[] = 
{
	L"asa",
	L"qwq",
};
//wstring prewrite;
//wcout.imbue(std::locale("chs"));

int _tmain(int argc,_TCHAR* argv[])
{
	prefun();
	Sleep(5000);
	while(1)
	{
		times--;
		if(times==0)
		{
			cout << "可选的关闭环节";
			S(6000);
			times = tire;
			system("cls");
		}
if(times==0)return 0;
		S(200);
		cout << times;
		ldat = dat;
		sget();
		if(doflag == true)
		{
			qmessage();
			doflag = false;
		}
	}
}

void prefun()
{
	QWrite();
	throwQFile();
	//wcout.imbue(locale("chs"));
	//wcout.imbue(locale(locale(),"",LC_CTYPE));
	//setlocale(LC_ALL, "");
}

void qmessage()
{
	if(dat.find_first_of(L'。')!=dat.find_last_of(L'。'))
	{
		wstring s = dat;
		s.push_back('。');
		bus = const_cast<wchar_t*>(s.c_str()); 
		qsend(bus);
	}
}

void sget()
{
	Qwnd;
	mgo(shortGet);
	S(10);
	mrdown;
	mrup;
	S(10);
	mgo(catByPoint);
	S(10);
	mdown;
	mup;
	dat = getCBoard();
	wcout << dat.c_str() << L"\n";cout << dat.size()<<'\n';
	if(dat!=ldat && dat!=eANSI)
	{
		if(dat.empty())
		{
			ofile << "Undefined IMG Expression";
		}
		else
		{
			doflag = true;
			#ifdef OUTDATA
			ofile << dat.c_str();
			#endif
		}
	}
}

wchar_t* AnsiToUnicode( const char* szStr )
{
       int nLen = MultiByteToWideChar( CP_ACP, MB_PRECOMPOSED, szStr, -1, NULL, 0 );
       if (nLen == 0)
       {
            return NULL;
       }
       wchar_t* pResult = new wchar_t[nLen];
       MultiByteToWideChar( CP_ACP, MB_PRECOMPOSED, szStr, -1, pResult, nLen );
       return pResult;
}

void uptdata()
{
	string::size_type saq = prewrite.find_last_of(L'【');
	lsdata = prewrite.substr(saq,prewrite.size()-saq);
	
} 

void tdata()
{
	bool have = false;
	int cnt = 0;
	string cut;
	for(char c : prewrite)
	{
		if(c=='\n')
		{
			if(have == false) continue;
			have = true;
			qdata[++cnt] = cut;
			cut.clear();
		}
		else
		{
			have = false;
			cut.push_back(c);
		}
	}
}

void qsend(wchar_t* ch)
{
	Qwnd;
	mgo(sending);
	mdown;
	mup;
	StringToClipBoard(ch);
	stick();
	ent();
}

void getinf()
{
	Qwnd;
	mgo(getting);
	mdown;
	mup;
	allcat();
	lsdata = getCBoard();
	uptdata();
	cout << (bool)(lsdata == lqdata);
	if(lsdata != lqdata)
	{
		#ifdef OUTDATA
		ofile << lsdata.c_str();
		#endif
	}
}

void allcat()
{
	kdown(17)
	kdown(65)
	kup(17)
	kup(65)
	kdown(17)
	kdown(67)
	kup(17)
	kup(67)
}

void cat()
{
	kdown(17)
	kdown(67)
	kup(17)
	kup(67)
}

void ent()
{
	kdown(13)
	kup(13)
}

void stick()
{
	kdown(17)
	kdown(86)
	kup(17)
	kup(86)
}

void QWrite()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

HWND qHWND()
{
	S(2000)
	GetCursorPos(pQset);
	Qwnd = 	WindowFromPoint(Qset);
	return Qwnd;
}

BOOL StringToClipBoard(wchar_t* srcString)
{
	BOOL bResult = FALSE;
	DWORD dwLength = wcslen(srcString);
	HANDLE hGlobalMemory = GlobalAlloc(GHND, dwLength + 1); // 分配内存
	LPBYTE lpGlobalMemory = (LPBYTE)GlobalLock(hGlobalMemory); // 锁定内存
	if ( NULL != lpGlobalMemory )
	{
		wcscpy((wchar_t*)lpGlobalMemory, srcString);
		::GlobalUnlock(hGlobalMemory); // 锁定内存块解锁
		::OpenClipboard(NULL); // 打开剪贴板
		::EmptyClipboard(); // 清空剪贴板
		::SetClipboardData(CF_TEXT, hGlobalMemory); // 将内存中的数据放置到剪贴板
		::CloseClipboard();

		bResult = TRUE;
	}
	return bResult;
}

void writeCBoard()
{
	HWND hWnd = NULL;
	OpenClipboard( hWnd );//打开剪切板
	EmptyClipboard();//清空剪切板
	HANDLE hHandle = GlobalAlloc(GMEM_FIXED, 1000);//分配内存
	char* pData = (char*) GlobalLock(hHandle);//锁定内存，返回申请内存的首地址
	strcpy(pData,"123");//或strcpy(pData, "this is a ClipBoard Test.");
	SetClipboardData(CF_TEXT, hHandle);//设置剪切板数据
	GlobalUnlock(hHandle);//解除锁定
	CloseClipboard();//关闭剪切板
}

char* getCBoard()
{
	char *url,*pData;
	size_t length;
	OpenClipboard(NULL);
	HANDLE hData=GetClipboardData(CF_TEXT);
	//assert(hData!=NULL);
	if(hData == NULL)
	{
		return eANSI;
	}
	length=GlobalSize(hData);
	url=(char*)malloc(length+1);
	pData=(char*)GlobalLock(hData);
	wcscpy(url,pData);
	GlobalUnlock(hData);
	CloseClipboard();
	url[length]=0;
	return url;
}

void throwQFile()
{
	if(getSysVersion()>9.99)
	{
		HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
		DWORD mode;
		GetConsoleMode(hStdin, &mode);
		mode &= ~ENABLE_QUICK_EDIT_MODE;
		SetConsoleMode(hStdin, mode);
		cout << "已移除快速编辑模式" << "\n" << endl; 
	}
}

float getSysVersion()
{
	float f_ret;
	typedef void(__stdcall*NTPROC)(DWORD*, DWORD*, DWORD*);
	DWORD dwMajor, dwMinor, dwBuildNumber;
	NTPROC proc = (NTPROC)GetProcAddress(
		LoadLibrary("ntdll.dll"),
		"RtlGetNtVersionNumbers"
	); proc(&dwMajor, &dwMinor, &dwBuildNumber); 
	// win 10
	if (dwMajor == 10 && dwMinor == 0)
	{
		f_ret = dwMajor + dwMinor*0.1;
		return f_ret;
	}
	// win 8.1
	if (dwMajor == 6 && dwMinor == 3)
	{
		f_ret = dwMajor + dwMinor*0.1;
		return f_ret;
	}
	// win 8.1 以下
	SYSTEM_INFO info;
	GetSystemInfo(&info);
	OSVERSIONINFOEX os;
	os.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	#pragma warning(disable:4996)
	if(GetVersionEx((OSVERSIONINFO *)&os))
	{
		f_ret = os.dwMajorVersion + os.dwMinorVersion*0.1;
	}
	return f_ret;
}
