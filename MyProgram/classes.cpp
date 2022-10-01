
#define _CRT_SECURE_NO_WARNINGS
#include"uni.h"
#include<iostream>
#include<cstdio>
#include<istream>
#include<ostream>
#include"classes.h"

using namespace std;

C::C() {
	this->CID = 0;;
	this->CName[30] = '\0';
	this->CSection = 0;
	this->CCredit = 0;;
}


C::~C()
{
}

ostream& operator<<(ostream& out, C& c)
{
	out << c.CID<<"\t" << c.CName<<"\t" << c.CSection <<"\t"<< c.CCredit;
	return out;
	// TODO: insert return statement here
}
