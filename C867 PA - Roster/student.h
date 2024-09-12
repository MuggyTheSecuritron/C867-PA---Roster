#pragma once
#include "degree.h"
#include <string>
#include <iostream>

using namespace std;
class Student {
public:
	//Student Object Constructor
	Student(string, string, string, string, int, int, int, int, DegreeProgram);

	//Getters
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetAge();
	int GetDaysInCourse(daysInCourseID);
	DegreeProgram GetDegreeProgram();

	//Setters
	void SetStudentID(string);
	void SetFirstName(string);
	void SetLastName(string);
	void SetEmailAddress(string);
	void SetAge(int);
	void SetDaysInCourse(int,int);
	void SetDegreeProgram(DegreeProgram);
	
	//Print
	void print();

private:
	//Private members
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
	DegreeProgram degreeProgram;

	

};