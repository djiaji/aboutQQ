#include<iostream>
#include<map>
#include<string>
#include<utility>
#include<algorithm>
#include<functional>
#include"messagerho.h"
using namespace MessageRho;
using namespace std;
int main(){
	string s;
	cin >> s;
	get_inf(s);
	ofstream ofile("data.txt");
	map<string,unsigned> mapp = get_preson_num(v);
	map<unsigned,unsigned> mappp = time_rho_hour(v);
	ofile << "bits=" <<bits<<"\n";
	ofile << "---preson---\n";
	vector<pair<unsigned,string>> vec;
	for(auto it:mapp){
		vec.push_back({it.second,it.first});
	}
	sort(vec.begin(),vec.end(),greater<pair<unsigned,string>>());
	for(auto it:vec){
		ofile << it.second << ' ' << it.first << ' ' << it.first*1.0/total*1.0 <<  '\n';
	}
	ofile << "---time---\n";

	for(auto it:mappp){
		ofile << it.first << ' ' << it.second <<'\n';
	}
}
