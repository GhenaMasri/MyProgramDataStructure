#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"uni.h" 
#include<cstdio>
#include<istream>
#include<ostream>
#include"classes.h"

using namespace std;

int main() {

	int x;
	int flag = 1, f = 1, f1 = 1;;
	Student* s;
	int size = 0;
	Student O;
	Student O1;
	int SID; int id; char n[20]; int section; int credit;
	int ss;

	C* ArrC;
	int s1, s2;
	bool g;
	Student n1, n2;


	int TS;

	FILE* P;
	
	P = fopen("student.txt", "r");
	if (!P) cout << "File couldn't be opened\n";
	else {

		fscanf(P, "%d", &TS);

	}

	fseek(P, 1, SEEK_SET);

	
	
	

	s = new Student[TS];
	cout << "Choose one of the following\n" << "1. Read student info from file \n" << "2. Print Student info \n" << "3. Add course to student's list of courses \n" << "4. Drop course from student's list of courses\n" << "5. Print Specific student info\n" << "6. Print Specific Course info for specific student\n" << "7. Check which student has the maximum load of courses\n" << "8. Exit \n";


	while (flag == 1) {
		cin >> x;
		switch (x) {
		case 1: for (int i = 0; i < TS; i++) { 
			fscanf(P, "%d %s %d", &s[i].studentID, s[i].studentName, &s[i].currentCourses);

			for (int j = 0; j < s[i].currentCourses; j++) {
				fscanf(P, "%d %s %d %d", &s[i].arrC[j].CID, s[i].arrC[j].CName, &s[i].arrC[j].CSection, &s[i].arrC[j].CCredit);

			}

		}
			  fclose(P);
			  break;
		case 2: for (int i = 0; i < TS; i++) {
			cout << "<<<< Students Details(id,name,number of current courses) >>>>" << endl;

			cout << s[i].studentID << "\t" << s[i].studentName << "\t" << s[i].currentCourses << endl;
			cout << "<<<< List of courses(id,name,section,credits) >>>>" << endl;
			for (int j = 0; j < s[i].currentCourses; j++) {

				cout << s[i].arrC[j].CID << "\t" << s[i].arrC[j].CName << "\t" << s[i].arrC[j].CSection << "\t" << s[i].arrC[j].CCredit << endl;
			}
			cout << "\n";

		} break;
		case 3:
			cout << "Please enter Student ID" << endl;
			cin >> SID;
			cout << "Please enter course ID,Name,Section,Credits" << endl;
			cin >> id;
			cin >> n;
			cin >> section;
			cin >> credit;

			for (int i = 0; i < TS; i++) {
				if (s[i].studentID == SID) {
				
					for (int j = 0; j < s[i].currentCourses; j++) {
						if (s[i].arrC[j].CID == id) {
							cout << "This course is already exists" << endl;
							f = 0;
						}
				
						}
					for (int j = 0; j < s[i].currentCourses; j++) {
						if (f == 0) break;
						if (s[i].arrC[j].CID != id && j == s[i].currentCourses - 1) {
							
							
							s = s->addCoures(SID, id, n, section, credit, s[i].currentCourses, TS, s);
						}
					}
					f = 1; 
					}
				}
			
		
			
		
			break;
		case 4: cout << "Please enter Student ID" << endl;
			cin >> SID;

			cout << "Please enter course ID" << endl;
			cin >> id;

			for (int i = 0; i < TS; i++) {
				if (s[i].studentID == SID) {
					for (int j = 0; j < s[i].currentCourses; j++) {
						if (s[i].arrC[j].CID == id) {
							s = s->dropCourse(SID, id, TS, s);
							f1 = 0;
						}
						if (f1 == 0) break;
						if(s[i].arrC[j].CID !=  id){
							
							if (j == s[i].currentCourses - 1)
								cout << "This course is not exists" << endl;



						}
					}
				}
			}

			break; 
		case 5: cout << "Please enter student ID" << endl;
			cin >> SID;
			ss = s->p_specificstudentInfo(SID, TS,s);
			
			cout << s[ss];

			break;
		case 6:cout << "Please enter student ID \n";
			cin >> SID;
			cout << "Please enter course ID" << endl;
			cin >> id;
			
			ArrC = s->p_studentCourses(SID, id, TS, s); 
			cout << *ArrC;

			break;
		case 7:cout <<"Please enter Student ID\n"; 
			cin >> s1;
			cout << "Please enter Student ID\n";
			cin >> s2;

			for (int i = 0; i < TS; i++) {
				if (s[i].studentID == s1) {
					n1 = s[i];
				}
				if (s[i].studentID == s2) {
					n2 = s[i];
				}
			}

			g = n1 > n2;
			if (g == 1) {
				cout << "The student with ID= " << n1.studentID << "\t over loaded more than student with ID= " << n2.studentID;
			}
			else cout << "The student with ID= " << n2.studentID << "\t over loaded more than student with ID= " << n1.studentID;


			break;


		case 8: cout << "8. Exit \n";
			flag = 0; break;
		}
		
		x = 0;

	}
	FILE* P1;
	P1 = fopen("NewStudent.txt", "w");
	for (int i = 0; i < TS; i++) {
		if(i==0) fprintf(P1, "%d\t%s\t%d\t", s[i].studentID, s[i].studentName, s[i].currentCourses);
		else fprintf(P1, "\n%d\t%s\t%d\t", s[i].studentID, s[i].studentName, s[i].currentCourses);
		for (int j = 0; j < s[i].currentCourses; j++) {
			fprintf(P1, "%d\t%s\t%d\t%d\t", s[i].arrC[j].CID, s[i].arrC[j].CName, s[i].arrC[j].CSection, s[i].arrC[j].CCredit);
			
		}
		

	}
	fclose(P1);
	delete[]s;
	return 0;
	
}

		


	


