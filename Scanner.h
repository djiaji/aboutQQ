#ifndef Scanner_H
#define Scanner_H
#include<vector>
#include<string>
#include<iostream>
#include"Exception.h"
namespace Scanner
{
	using namespace std;
	class func
	{
	public:
		string name;
		vector<string> args;
		void clear(){
			name.clear();
			args.clear();
		}
		bool empty(){
			if(name.empty()&&args.empty())
				return 1;
			return 0;
		}
		void output(){
			puts("__func__");
			cout << "name: " << name << '\n'
				 << "args: ";
			for(string s:args)
				cout << s << "  ";
			puts("\n__end_func__\n");
		}
	};
	string&input_format(string& from){
		while(from[0]==' '){
			if(from.empty())break;
			from.erase(from.begin());
		}
		while(from[from.size()-1]==' '){
			if(from.empty())break;
			from.pop_back();
		}
		return from;
	}
	enum scan_cases{none,naming,arging};
	void sc_error(int clm,scan_cases sc){
		string s = "Scan Cases Error in column ";
		s.append(to_string(clm));
		s += ": Unexpected Token ";
		if(sc==arging){
			s += "Arging,You may missed adding operator\']\' in the end of a function";
		}
		else if(sc==naming){
			s += "Naming,You may missed adding operator\'[\' at the beginning of arguments";
		}
		else if(sc==none){
			s += "Empty_Type,You may missed adding operator\'-\' at the beginning of a function";
		}
		Exception::error("Function sc_error in head file \"Scanner.h\"",s);
	}
	vector<func> scan(string& cmd)
	{
		int cnt = 0;
		vector<func> ret;
		func nowf;
		string s;
		scan_cases sc = none;
		for(char c : cmd)
		{
			++cnt;
			if(c==' ')
				continue;
			else if(c=='-'){
				if(!s.empty())
					sc_error(cnt,sc);
				sc = naming;
			}
			else if(c=='['){
				sc = arging;
				nowf.name = s;
				s.clear();
			}
			else if(c==','){
				if(!s.empty())nowf.args.push_back(s);
				s.clear();
			}
			else if(c==']'){
				if(!s.empty())nowf.args.push_back(s);
				s.clear();
				sc = none;
				if(!nowf.empty())
				ret.push_back(nowf);
				nowf.clear();
			}
			else {
				s.push_back(c);
			}
		}
		if(ret.empty()){
			sc_error(2147483647,naming);
		}
		if(sc!=none){
			sc_error(2147483647,sc);
		}
		return ret;
	}
}
#endif
