#include <string>
#include <iostream>
#include "student.h"
#include "degree.h"
using namespace std;

//Constructor Definition
Student::Student(string StudentIDData, string FirstNameData, string LastNameData, string EmailAddressData, int AgeData, int DaysInCourse1Data,int DaysInCourse2Data,int DaysInCourse3Data, DegreeProgram DegreeProgramData) {
	studentID = StudentIDData;
	firstName = FirstNameData;
	lastName = LastNameData;
	emailAddress = EmailAddressData;
	age = AgeData;
	daysInCourse[0] = DaysInCourse1Data;
	daysInCourse[1] = DaysInCourse2Data;
	daysInCourse[2] = DaysInCourse3Data;
	degreeProgram = DegreeProgramData;
}

//Setter Definitions
void Student::SetStudentID(string studentIDData) {
	studentID = studentIDData;
}
void Student::SetFirstName(string firstNameData) {
	firstName = firstNameData;
}
void Student::SetLastName(string lastNameData) {
	lastName = lastNameData;
}
void Student::SetEmailAddress(string emailAddressData) {
	emailAddress = emailAddressData;
}
void Student::SetAge(int ageData) {
	age = ageData;
}
void Student::SetDaysInCourse(int daysInCourseData, int index) {
	daysInCourse[index - 1] = daysInCourseData;
}
void Student::SetDegreeProgram(DegreeProgram degreeProgramData) {
	degreeProgram = degreeProgramData;
}

//Getter Definitions
string Student::GetStudentID() {
	return studentID;
}
string Student::GetFirstName() {
	return firstName;
}
string Student::GetLastName() {
	return lastName;
}
string Student::GetEmailAddress() {
	return emailAddress;
}
int Student::GetAge() {
	return age;
}
int Student::GetDaysInCourse(daysInCourseID typeData) {
	int avgDays;
	if (typeData == ONE) {
		return daysInCourse[0];
	}
	else if (typeData == TWO) {
		return daysInCourse[1];
	}
	else if (typeData == THREE) {
		return daysInCourse[2];
	}
	else if (typeData == AVG) {
		avgDays = 0;
		for (int i = 0; i < 3; ++i) {
			avgDays = avgDays + daysInCourse[i];
		}
		avgDays = avgDays / 3;
		return avgDays;
	}
	else {
		cout << "Error: Invalid type!";
		return -1;
	}
}
DegreeProgram Student::GetDegreeProgram() {
	return degreeProgram;
}

//Print Function (Student Objects)
void Student::print() {
	string degreePrint;

	switch(GetDegreeProgram()) {
		case SECURITY:
			degreePrint = "SECURITY";
			break;

		case NETWORK:
			degreePrint = "NETWORK";
			break;

		case SOFTWARE:
			degreePrint = "SOFTWARE";
			break;
	}
	string days1 = to_string(GetDaysInCourse(ONE));
	string days2 = to_string(GetDaysInCourse(TWO));
	string days3 = to_string(GetDaysInCourse(THREE));

	cout << "Student ID: " << GetStudentID() << "\tFirst Name: " << GetFirstName() << "\tLast name: " << GetLastName() << "\tEmail Address: " << GetEmailAddress() << "\tAge: " << GetAge() << "\t\tDays In Courses: { " << days1 << "," << days2 << ","  << days3 << " }" << "\tAverage Days: " << GetDaysInCourse(AVG) << "\tDegree Program: " << degreePrint << endl;
}

