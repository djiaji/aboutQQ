#include<iostream>
#include<string>
#include<Windows.h>
#include"NameFmt.h"
#include"Scanner.h"
using namespace std;
int main(){
	string str;
	getline(cin,str);
	vector<Scanner::func> v = Scanner::scan(str);
	NameFmt::spreader(v);
	system("pause");
	return 0;
}
