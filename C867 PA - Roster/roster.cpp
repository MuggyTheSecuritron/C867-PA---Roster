#include "roster.h"
#include <string>
#include <iostream>

using namespace std;
//Constructor
Roster::Roster() {
	Student* ClassRosterArray[5];
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse1;
	int daysInCourse2;
	int daysInCourse3;
	DegreeProgram degreeProgram;
	string degreeProgramString;

	const string studentData[] =
		
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,William,Romero,browegamin@gmail.com,24,15,20,25,SOFTWARE"
	};
	
	int i;

	for (i = 0; i < classRosterArraySize; ++i) {
		string parsing = studentData[i];
		
		size_t rhs = parsing.find(',');
		studentID = parsing.substr(0, rhs);
		size_t lhs = rhs + 1;
		rhs = parsing.find(',',lhs);
		firstName = parsing.substr(lhs, rhs - lhs);
		lhs = rhs + 1;
		rhs = parsing.find(',', lhs);
		lastName = parsing.substr(lhs, rhs - lhs);
		lhs = rhs + 1;
		rhs = parsing.find(',', lhs);
		emailAddress = parsing.substr(lhs, rhs - lhs);
		lhs = rhs + 1;
		rhs = parsing.find(',', lhs);
		age = stoi(parsing.substr(lhs, rhs - lhs));
		lhs = rhs + 1;
		rhs = parsing.find(',', lhs);
		daysInCourse1 = stoi(parsing.substr(lhs, rhs - lhs));
		lhs = rhs + 1;
		rhs = parsing.find(',', lhs);
		daysInCourse2 = stoi(parsing.substr(lhs, rhs - lhs));
		lhs = rhs + 1;
		rhs = parsing.find(',', lhs);
		daysInCourse3 = stoi(parsing.substr(lhs, rhs - lhs));
		lhs = rhs + 1;
		rhs = parsing.find(',', lhs);
		degreeProgramString = parsing.substr(lhs, rhs - lhs);
		if (degreeProgramString == "SECURITY") {
			degreeProgram = SECURITY;
		}
		else if (degreeProgramString == "NETWORK") {
			degreeProgram = NETWORK;
		}
		else if (degreeProgramString == "SOFTWARE") {
			degreeProgram = SOFTWARE;
		}
		else {
			degreeProgram = BONK;
		}
		AddStudentToArray(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram,i);



	}


}

//Destructor
Roster::~Roster() {
	cout << "Destroying";
}

//Function Definitions
void Roster::AddStudentToArray(string studentID, string firstName, string lastName, string emailAddress, int age, int DIC1, int DIC2, int DIC3, DegreeProgram degreeProgram, int index) {

	ClassRosterArray[index] = new Student(studentID, firstName, lastName, emailAddress, age, DIC1, DIC2, DIC3, degreeProgram);

}
void Roster::RemoveStudentByID(string studentID) {
	int index;
	bool found = false;
	string IDCompare;
	for (int i = 0; i < classRosterArraySize; ++i) {
		if (ClassRosterArray[i] != 0) {
			IDCompare = ClassRosterArray[i]->GetStudentID();
			if (IDCompare == studentID) {
				found = true;
				ClassRosterArray[i] = 0;
				break;
			} else {
				continue;
			}
		}
		else {
			continue;
		}
	}
	if (!found) {
		cout << "Student with ID: {" << studentID << "} not found!" << endl;
	}
	
	
}
void Roster::PrintAll() {
	for (int i = 0; i < classRosterArraySize; ++i) {
		if (ClassRosterArray[i] != 0) {
			ClassRosterArray[i]->print();
		}
	}
	cout << endl;
}
void Roster::PrintAvgDaysInCourse(string studentID) {
	string IDCompare = studentID;
	for (int i = 0; i < classRosterArraySize; ++i) {
		if (ClassRosterArray[i] != 0) {
			if (ClassRosterArray[i]->GetStudentID() == IDCompare) {
				//Match Found
				cout << "Average days in courses: " << ClassRosterArray[i]->GetDaysInCourse(AVG) << endl;
				break;
			}
			else {
				continue;
			}
		}
		else {
			continue;
		}
	}
}
void Roster::PrintInvalidEmails() {
	bool emailValid = true;
	cout << "Checking for invalid emails..." << endl;
    for (int i = 0; i < classRosterArraySize; ++i) {
        string emailTester = ClassRosterArray[i]->GetEmailAddress();
        if (emailTester.find(' ') != string::npos || emailTester.find('@') == string::npos || emailTester.find('.') == string::npos) {
            cout << "Invalid email: " << emailTester << " for student ID " << ClassRosterArray[i]->GetStudentID() << endl;
			emailValid = false;
        }
    }
	if (emailValid) {
		cout << "All emails are valid!" << endl;
	}
}
void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < classRosterArraySize; ++i) {
		if (ClassRosterArray[i] != 0 && ClassRosterArray[i] != nullptr) {
			if (ClassRosterArray[i]->GetDegreeProgram() == degreeProgram) {
				ClassRosterArray[i]->print();
			} else {
				continue;
			} 


		} else {
			continue;
		}
	}
}