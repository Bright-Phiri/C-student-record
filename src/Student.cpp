#include "Student.h"
#include <iostream>
#include <cstring>

using namespace std;

Student::Student(){
}

Student::~Student(){
}

char* Student::getStudentName(){
    return this->studentName;
}

void Student::setStudentName(char studentName[30]){
     strcpy(this->studentName,studentName);
}

char* Student::getStudentGender(){
    return this->studentGender;
}

void Student::setStudentGender(char studentGender[8]){
     strcpy(this->studentGender,studentGender);
}

int Student::getStudentAge(){
    return this->studentAge;
}

void Student::setStudentAge(int age){
     this->studentAge = age;
}

char* Student::getStudentAddress(){
    return this->studentAddress;
}

void Student::setStudentAddress(char studentAddress[40]){
    strcpy(this->studentAddress,studentAddress);
}

char* Student::getStudentPhoneNumber(){
    return this->studentPhoneNumber;
}

void Student::setStudentPhoneNumber(char studentPhoneNumber[16]){
    strcpy(this->studentPhoneNumber,studentPhoneNumber);
}

void Student::showStudentDetails(){
     cout << "\nSTUDENT NAME    : " << studentName;
     cout << "\nSTUDENT GENDER  : " << studentGender;
     cout << "\nSTUDENT AGE     : " << studentAge;
     cout << "\nSTUDENT ADDRESS : " << studentAddress;
     cout << "\nSTUDENT PHONE   : " << studentPhoneNumber <<endl <<endl;
}
