#ifndef NameFmt_H
#define NameFmt_H
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<set>
#include"Scanner.h"
#include"Exception.h"


//捏麻麻的等2023年了tm千万别忘改了
const std::string year = "2022/";



using namespace std;
namespace Pool
{
	vector<string> _log;
	vector<string> IOpool;
	set<string> names;
	vector<string> name;
	vector<string> v;	//orginal
	vector<string> usev;
	ifstream infile;
	bool haveinf;
}
namespace BuiltinFunction
{
	void MoreArgsException(const char* expected,int real,const char* function_name)
	{
		string s = "There are too many arguments in ";
		s += function_name;
		s += ",";
		s += to_string(real);
		s += ",expected ";
		s += expected;
		Exception::error("MoreArgsException in namespace BuiltinFunction,head file NameFmt.h",s);
	}
	void UnknownArgc(string arg,const char* function_name,const char* more="")
	{
		string s = "Unknown argument ";
		s += arg;
		s += " in ";
		s += function_name;
		s += " ";
		s += more;
		Exception::error("MoreArgsException in namespace BuiltinFunction,head file NameFmt.h",s);
	}
	void NonInput()
	{
		Exception::error("NonInput in namespace BuiltinFunction,head file NameFmt.h","no input");
	}
	inline bool asciiNum(char c){
		return (c>='0'&&c<='9');
	}
	inline bool asciiLetter(char c){
		return (c>='a'&&c<='z'||c>='A'&&c<='Z');
	}
	bool checkTime(const string& s)
	{
		if(s.size()<7)return false;
		string str = s.substr(s.size()-7);
		if(str[1]==':'&&str[4]==':'){
			if(asciiNum(str[0])&&asciiNum(str[2])&&asciiNum(str[3])&&asciiNum(str[5])&&asciiNum(str[6])){
				if(stoi(str.substr(str.size()-2))<60&&stoi(str.substr(str.size()-5,2))<60)
					return true;
			}
		}
		return false;
	}
	void delete_space(string& s)
	{
		while(s[0]==' '){
			if(s.empty())break;
			s.erase(s.begin());
		}
		while(s[s.size()-1]==' '){
			if(s.empty())break;
			s.pop_back();
		}
	}
}
namespace IO
{
	using namespace Pool;
	using namespace BuiltinFunction;
	string dealFile(string s){
		auto x = s.find("files:");
		if(x!=s.npos)
			s.erase(0,x+6);
		delete_space(s);
		return s;
	}
	void opt(const vector<string>& args)
	{
		bool cleared=0,infp=0,nostd=0,namef=0;
		string fl;
		if(args.size()>3)MoreArgsException("0 to 3",args.size(),"opt,IO");
		for(string s : args){
			if(s=="clear")cleared = 1;
			else if(s=="IOpool")continue;
			else if(s=="infpool"||s=="usepool"||s=="usev")infp=1;
			else if(s=="name")namef=1;
			else if(s.find("files:")!=s.npos)nostd=1,fl=dealFile(s);
			else UnknownArgc(s,"opt,IO");
		}
		if(nostd){
			ofstream ofile(fl);
			if(infp){
				for(string s:usev)
					ofile << s << '\n';
				if(cleared)
					usev.clear();
			}
			else if(namef){
				for(string s:name)
					ofile << s << '\n';
				if(cleared)
					name.clear();
			}
			else {
				for(string s:IOpool)
					ofile << s << '\n';
				if(cleared)
					IOpool.clear();
			}
		}
		else{
			if(infp){
				for(string s:usev)
					cout << s << '\n';
				if(cleared)
					usev.clear();
			}
			else if(namef){
				for(string s:name)
					cout << s << '\n';
				if(cleared)
					name.clear();
			}
			else{
				for(string s:IOpool)
					cout << s << '\n';
				if(cleared)
					IOpool.clear();
			}
		}
			for(string s : IOpool)
				cout << s << '\n';
		_log.push_back("opt output IOpool");
		if(cleared){
			_log.push_back("opt cleared IOpool");
			IOpool.clear();
		}
	}
	void show_log(const vector<string>& args)
	{
		if(args.size()>1)MoreArgsException("0 or 1",args.size(),"show_log,IO");
		if(!args.empty()){
			ofstream ofile(args[0]);
			for(string s : _log)
				ofile << s << '\n';
		}
		else
			for(string s : _log)
				cout << s << '\n';
	}
	void inp(const vector<string>& args){
		if(args.size()!=1)MoreArgsException("1",args.size(),"show_log,IO");
		string s = args[0];
		s = dealFile(s);
		infile.open(s);
		haveinf = 1;
		string str;
		while(getline(infile,str)){
			v.push_back(str);
		}
		usev = v;
		_log.push_back("input file");
	}
}
namespace SimpleFunction
{
	using namespace BuiltinFunction;
	using namespace Pool;
	void void_function(vector<string>& args,const char* function_name)
	{
		string s = function_name;
		s += ",SimpleFunction";
		if(!haveinf)NonInput();
		if(!args.empty())MoreArgsException("0",args.size(),s.c_str());
	}
	void catchQName(const vector<string>& args)
	{
		if(!haveinf)NonInput();
		if(!args.empty())MoreArgsException("0",args.size(),"catchQName,SimpleFunction");
		for(string s:v){
			if(checkTime(s)){
				auto x = s.find("【");
				if(x!=s.npos){
					s.erase(x,s.find("】")+2);
				}
				s.erase(s.end()-7,s.end());
				if(asciiNum(s[s.size()-1]))
					s.erase(s.size()-1);
				x = s.find(year);
				if(x!=s.npos){
					s.erase(x);
				}
				delete_space(s);
				names.insert(s);
			}
		}
		_log.push_back("QName was inserted,here are names:");
		for(auto s:names)
			name.push_back(s);
		for(auto s:name)
			_log.push_back(s);
		_log.push_back("Here are names");
	}
	void delBasicQName(const vector<string>& args)
	{
		if(!haveinf)NonInput();
		bool opt = 0;
		vector<string> warnings;
		if(args.size()>1)MoreArgsException("0 or 1",args.size(),"delBasicQName,SimpleFunction");
		if(args.size()==1){
			if(args[0]!="o")UnknownArgc(args[0],"delBasicQName,SimpleFunction");
			else opt = 1;
		}
		for(auto it=usev.begin();it!=usev.end();++it){
			if(checkTime(*it))
				usev.erase(it);
			if(it->empty())
				usev.erase(it);
			for(string p:name){
				auto x = it->find(p);
				if(x!=it->npos){
					it->erase(x,x+p.size());
					if(!it->empty()&&(*it)[0]=='@')
						it->erase(it->begin());
				}
			}
		}
		for(int i=0;i!=usev.size();++i){
			for(int j=0;j!=usev[i].size();++j)
				if(usev[i][j]=='@'){
				string s = "Warning: In line ";
				s += to_string(i+1);
				s += "column ";
				s += to_string(j+1);
				s += " operator \'@\' maybe with a name";
				usev.push_back(s);
			}
		}
		if(opt){
			for(string& s:usev){
				IOpool.push_back(s);
			}
		}
	}
	void maybeName(){
		for(int i=0;i!=usev.size();++i){
			for(int j=2;j<usev[i].size();++j){
				//检验是否有两个或三个连续的字母。
			}
		}
	}
	void replace(const vector<string>& args){
		if(!haveinf)NonInput();
		string to = args[0];
		for(int i=0;i<usev.size();++i){
			for(int j=1;j<args.size();++j){
				while(usev[i].find(args[j])!=usev[i].npos)
				usev[i]=usev[i].replace(usev[i].find(args[j]),args[j].size(),to);
			}
		}
	}
}
namespace NameFmt
{
	using namespace SimpleFunction;
	using namespace Exception;
	using namespace Scanner;
	using namespace std;
	using namespace IO;
	void spreader(const vector<func>& funs)
	{
		_log.push_back("Application started");
		string __s = "Spreader has received function packages which size is ";
		__s += to_string(funs.size());
		_log.push_back(__s);
		int cnt = 0;
		for(func fc : funs)
		{
			++cnt;
			string& n = fc.name;
			if(n=="o")opt(fc.args);
			else if(n=="i")inp(fc.args);
			else if(n=="showlog")show_log(fc.args);
			else if(n=="delBasicQName")delBasicQName(fc.args);
			else if(n=="catchQName")catchQName(fc.args);
			else if(n=="replace")replace(fc.args);
			else
			{
				string s = "Unknown Function called [";
				s += n;
				s += "] in functions ";
				s += to_string(cnt);
				error("Spreader in head file \"NameFmt\"",s);
			}
			string s = "Spreader has spread the ";
			s += to_string(cnt);
			if(cnt%10==1&&cnt!=11)
				s += "st";
			else if(cnt%10==2&&cnt!=12)
				s += "nd";
			else if(cnt%10==3&&cnt!=13)
				s += "rd";
			else s += "th";
			s += " function named \'";
			s += n;
			s += "\' successfully";
			_log.push_back(s);
		}
	}
}
#endif
