#include<iostream>
#include<cstdlib>
#include<wchar.h>
#include<string>
#include<cstring>
#include<locale>
using namespace std;
void preparation();
int main()
{
	preparation();
	wstring s;
	wcin >> s;
	wcout << s << L'\n';
//	for(auto it=s.begin();it!=s.end();++it)
//	wcout << *it << L' ';
	return 0;
}
void preparation()
{
	setlocale(LC_ALL,"zh-CN");
	system("chcp 65001");
	wcout.imbue(locale(""));
}
