#define _CRT_SECURE_NO_WARNINGS
#include"uni.h"
#include<iostream>
#include<cstdio>
#include<istream>
#include<ostream>
#include"classes.h"

using namespace std;








Student::Student()
{
	this->SIZE;
	this->studentID = 0;
	this->studentName[20]='\0';
	
	this->currentCourses = 0;
	this->arrC[5];
	for (int i = 0; i < 5; i++) {
		this->arrC[i].CID = 0;
		this->arrC[i].CName[30] = '\0';
		this->arrC[i].CSection = 0;
		this->arrC[i].CCredit = 0;
	}
} 

Student::~Student()
{
}



Student* Student::addCoures(int SID,int id, char n[30], int section, int credit, int index,int TS,Student *&s){



     SIZE = TS;
	 Student* M = new Student[SIZE];
	M = s;
	

		for (int i = 0; i < SIZE; i++) {
			
			if (s[i].studentID == SID) { 
				s[i].currentCourses = ++index;
				
			
				for (int l = (s[i].currentCourses - 1); l < (s[i].currentCourses); l++) { 

					s[i].arrC[l].CID = id;
					strcpy(s[i].arrC[l].CName, n);
					s[i].arrC[l].CSection = section; 

					s[i].arrC[l].CCredit = credit;


				
				}
				}
			}
		
		return M;
		delete[]M;

}

	

	





Student* Student::dropCourse(int SID, int id,int TS, Student *&s)
{
	this->SIZE = TS;
	int k;
	Student* M = new Student[SIZE];
	M = s;

	for (int i = 0; i < SIZE; i++) {
		if (s[i].studentID == SID) {
			for (int j = 0; j < s[i].currentCourses; j++) {
				if (s[i].arrC[j].CID == id) {
					for (k = j; k < s[i].currentCourses; k++) {
						s[i].arrC[k].CID = s[i].arrC[k + 1].CID;
						strcpy(s[i].arrC[k].CName, s[i].arrC[k + 1].CName);

						s[i].arrC[k].CSection = s[i].arrC[k + 1].CSection;
						s[i].arrC[k].CCredit = s[i].arrC[k + 1].CCredit;
					}
					s[i].currentCourses = s[i].currentCourses - 1;

					}

				}
			}
		}
	return M;
	delete[]M;
	}


C* Student::p_studentCourses(int SID, int id,int TS, Student *&s)
{
	this->SIZE = TS;
	Student* M = new Student[SIZE];
	M = s;
	C* Arr=new C[1];
	for (int i = 0; i < SIZE; i++) {
		if (s[i].studentID == SID) {
			
			for (int j = 0; j < s[i].currentCourses; j++) {
				if (s[i].arrC[j].CID == id) {
				Arr[0].CID = s[i].arrC[j].CID;
				strcpy(Arr[0].CName, s[i].arrC[j].CName);
				Arr[0].CSection = s[i].arrC[j].CSection;
				Arr[0].CCredit = s[i].arrC[j].CCredit;
				return Arr;
			}

			
			}
		}
	}
	delete[]M;
	return 0;
}

int Student::p_specificstudentInfo(int SID,int TS, Student *&s)
{
	this->SIZE = TS;
	Student* M = new Student[SIZE];
	M = s;
	int a = 0;

	for (int i = 0; i < SIZE; i++) {
		if (s[i].studentID == SID) {
			a = 1;
			return i;
		}
	}
	delete[]M;
		 return 0;
		

	
		
	


}

bool Student::operator>(Student n2)
{
	if (currentCourses > n2.currentCourses) {
	return true;
}
 else return false;
}





ostream & operator<<(ostream &out, Student &s)
{
	out << s.studentID << "\t" << s.studentName << "\t" << s.currentCourses << endl;
	out<< "<<<< List of courses(id,name,section,credits) >>>>" << endl;
	for (int i = 0; i < s.currentCourses; i++) {
		cout << s.arrC[i].CID << "\t" << s.arrC[i].CName << "\t" << s.arrC[i].CSection << "\t" << s.arrC[i].CCredit << endl;
	}

	return out;
	// TODO: insert return statement here
}