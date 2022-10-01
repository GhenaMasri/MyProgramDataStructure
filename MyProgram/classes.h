#pragma once
#include"uni.h"
#include<istream>
#include<ostream>
#include<iostream>
using namespace std;

class C {
public: int CID;
	  char CName[30];
	  int CSection;
	  int CCredit;
	  C();
	  ~C();
	  friend ostream& operator<<(ostream& out,C& c);



};

