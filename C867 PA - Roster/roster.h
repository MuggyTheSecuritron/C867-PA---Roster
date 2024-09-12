#pragma once
#include "student.h"
class Roster {
public:
	//Constructor
	Roster();

	//Destructor
	~Roster();

	//Roster Manipulation
	void AddStudentToArray(string, string, string, string, int, int, int, int, DegreeProgram, int);
	void RemoveStudentByID(string);

	//Array
	Student* ClassRosterArray[5];
	int classRosterArraySize = sizeof(ClassRosterArray) / sizeof(ClassRosterArray[0]);

	//Print Functions
	void PrintAll();
	void PrintAvgDaysInCourse(string);
	void PrintInvalidEmails();
	void PrintByDegreeProgram(DegreeProgram);
};