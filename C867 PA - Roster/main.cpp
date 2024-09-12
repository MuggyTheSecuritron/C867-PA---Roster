// C867 PA - Roster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
using namespace std;


int main()
{
    cout << "C867" << "\tC++" << "\tID: 011139923" << "\tWilliam Romero" << endl << endl;

    //For testing accessor/mutators for the student class
    //Student studentTest("A6","William","Romero","william.romero511@gmail.com",24,15,20,25,SOFTWARE);

    Roster classRoster;


    classRoster.PrintAll();

    classRoster.PrintInvalidEmails();

    int rosterSize = sizeof(classRoster.ClassRosterArray) / sizeof(classRoster.ClassRosterArray[0]);

    for (int i = 0; i < rosterSize; ++i) {
        if (classRoster.ClassRosterArray[i] != 0 && classRoster.ClassRosterArray[i] != nullptr) {

            string IDInput = classRoster.ClassRosterArray[i]->GetStudentID();

            classRoster.PrintAvgDaysInCourse(IDInput);

            continue;

        }
        else {

            continue;

        }
    }

    classRoster.PrintByDegreeProgram(SOFTWARE);

    classRoster.RemoveStudentByID("A3");

    classRoster.PrintAll();

    classRoster.RemoveStudentByID("A3");
    
    
    
    
    
    
   //more testing for student class
   /* cout << studentTest.GetStudentID() << endl;
    cout << studentTest.GetFirstName() << endl;
    cout << studentTest.GetLastName() << endl;
    cout << studentTest.GetEmailAddress() << endl;
    cout << studentTest.GetAge() << endl;
    cout << studentTest.GetDaysInCourse(ONE) << endl;
    cout << studentTest.GetDaysInCourse(TWO) << endl;
    cout << studentTest.GetDaysInCourse(THREE) << endl;
    cout << studentTest.GetDaysInCourse(AVG) << endl;
    cout << studentTest.GetDegreeProgram() << endl;

    studentTest.SetStudentID("A7");
    studentTest.SetFirstName("Caslyn");
    studentTest.SetLastName("Suire");
    studentTest.SetEmailAddress("caslynsuire@gmail.com");
    studentTest.SetAge(25);
    studentTest.SetDaysInCourse(50,1);
    studentTest.SetDaysInCourse(75,2);
    studentTest.SetDaysInCourse(100,3);
    studentTest.SetDegreeProgram(NETWORK);

    cout << studentTest.GetStudentID() << endl;
    cout << studentTest.GetFirstName() << endl;
    cout << studentTest.GetLastName() << endl;
    cout << studentTest.GetEmailAddress() << endl;
    cout << studentTest.GetAge() << endl;
    cout << studentTest.GetDaysInCourse(ONE) << endl;
    cout << studentTest.GetDaysInCourse(TWO) << endl;
    cout << studentTest.GetDaysInCourse(THREE) << endl;
    cout << studentTest.GetDaysInCourse(AVG) << endl;
    cout << studentTest.GetDegreeProgram() << endl;*/

}