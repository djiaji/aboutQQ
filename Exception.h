#ifndef Exception_H
#define Exception_H
#include<string>
#include<iostream>
namespace Exception
{
	using namespace std;
	void error(const char* caller,string exception){
		puts("Exception.h :");
		cout << "Called by[" << caller << "]: " << exception;
		exit(-1);
	}
}
#endif
