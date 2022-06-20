#ifndef MESSAGERHO_H
#define MESSAGERHO_H

#include<iostream>
#include<fstream>
#include<set>
#include<map>
#include"NameFmt.h"
using namespace BuiltinFunction;
using namespace std;
namespace MessageRho
{
	vector<string> v;
	struct _t
	{
		unsigned hour,minute,second;
		bool null;
		_t(){
			hour=0,minute=0,second=0;
			null = 1;

		}
		_t(unsigned h,unsigned m,unsigned s){
			hour = h, minute = m, second = s;
			null = 0;
		}
	};
	unsigned bits,total;
	map<string,unsigned> get_preson_num(vector<string> source)
	{
		map<string,unsigned> names;
		for(string s:source){
			if(checkTime(s)){++total;
				auto x = s.find("¡¾");
				if(x!=s.npos){
					s.erase(x,s.find("¡¿")+2);
				}
				s.erase(s.end()-7,s.end());
				if(asciiNum(s[s.size()-1]))
					s.erase(s.size()-1);
				x = s.find(year);
				if(x!=s.npos){
					s.erase(x);
				}
				delete_space(s);
				if(names.count(s))
					++names[s];
				else
					names.insert({s,1});
			}
		}
		return names;
	}

	_t solve_time(const string& s)
	{
		_t ret;
		if(!checkTime(s))
		return ret;
		int se = stoi(s.substr(s.size()-2));
		int mi = stoi(s.substr(s.size()-5,2));
		int ho;
		if(s.size()>=8&&asciiNum(s.size()-8))
			ho = stoi(s.substr(s.size()-8,2));
		else ho = stoi(s.substr(s.size()-7,1));
		ret = {(unsigned)ho,(unsigned)mi,(unsigned)se};
		return ret;
	}

	void preson_rho()
	{

	}

	map<unsigned,unsigned> time_rho_hour(vector<string> source)
	{
		map<unsigned,unsigned> m;
		for(string s:source){
			_t t = solve_time(s);
			if(!t.null){
				if(m.count(t.hour))
					++m[t.hour];
				else m.insert({t.hour,1});
				cout << s << " " <<t.hour<<' ' <<t.minute<<' '<<t.second<<"\n";
			}else{
				bits += s.size();
			}
		}
		return m;
	}


	void get_inf(string in)
	{
		ifstream infile(in);
		string s;
		while(getline(infile,s))
			v.push_back(s);
	}
}

#endif
