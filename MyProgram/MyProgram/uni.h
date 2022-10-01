#pragma once
#include<istream>
#include<ostream>
#include<iostream>
#include"classes.h"
using namespace std;




class Student {
public:
	int SIZE;
	int studentID;
	  char studentName[20];
	  int currentCourses;
	  int MANOC = 5;
	  
	  
	  C arrC[5]; 
	 
	
	  Student();
	  ~Student();
	


Student* addCoures(int SID,int id,char n[30],int section,int credit,int index,int TS,Student *&s);
	Student* dropCourse(int SID, int id,int TS,Student *&s);
	C* p_studentCourses(int SID, int id,int TS,Student *&s); 
	 int p_specificstudentInfo(int SID,int TS, Student *&s); 
	 
	 friend ostream & operator<<(ostream & out, Student & s);
	 bool operator > (Student n2);
	 



};

