#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <windows.h>
#include <conio.h>
#include "Student.h"

using namespace std;


//Function parameters
void AddStudentRecord();
void DisplayStudentRecord();
void SearchStudentRecord();
void UpdateStudentRecord();
void DeleteStudentRecord();
void Menu();

int main(){
    Menu();
    return 0;
}

void AddStudentRecord(){
     ofstream outputFile;
     Student student;
     int option;
     char studentName[30];
     char studentGender[8];
     int studentAge;
     char studentAddress[40];
     char studentPhone[16];
     outputFile.open("Student.bin",ios::binary | ios::out | ios::app);
     if (outputFile.fail()){
        cerr << "Error while opening the file!" <<endl;
        exit(EXIT_FAILURE);
     } else{
         cout << "ENTER STUDENT NAME" <<endl;
         cin.getline(studentName,40);
         cout << "ENTER STUDENT GENDER" <<endl;
         cin >> studentGender;
         cout << "ENTER STUDENT AGE" <<endl;
         cin >> studentAge;
         cin.ignore(256,'\n');
         cout << "ENTER STUDENT ADDRESS" <<endl;
         cin.getline(studentAddress,40);
         cout << "ENTER STUDENT PHONE NUMBER" <<endl;
         cin.getline(studentPhone,16);
         student.setStudentName(studentName);
         student.setStudentGender(studentGender);
         student.setStudentAge(studentAge);
         student.setStudentAddress(studentAddress);
         student.setStudentPhoneNumber(studentPhone);
         cout << "PRESS 1 TO SAVE THE RECORD OR PRESS 2 TO CANCEL" <<endl;
         cin >> option;
         switch (option){
         case 1:
            outputFile.write((char*)&student,sizeof(student));
            cout << "RECORD SAVED TO THE FILE" <<endl;
            outputFile.close();
            break;
         case 2:
            cout << "SAVE OPERATION CANCELED" <<endl;
            break;
         default:
             cout << "WRONG OPTION!" <<endl;
            break;
         }
     }
}

void DisplayStudentRecord(){
     ifstream inputFile;
     Student student;
     bool isStudentsDataAvailable = false;
     inputFile.open("Student.bin",ios::binary | ios::in);
     if (inputFile.fail()){
        cout << "Unable to open the file!" <<endl;
        exit(EXIT_FAILURE);
     } else{
         while (inputFile.read((char*)&student,sizeof(student))){
            isStudentsDataAvailable = true;
            student.showStudentDetails();
         }
         if (isStudentsDataAvailable == false){
            cout << " No records found in the file " <<endl;
         }
     }
     inputFile.close();
}

void SearchStudentRecord(){
     ifstream inputFile;
     Student student;
     bool isStudentsDataAvailable = false;
     char studentName[30];
     inputFile.open("Student.bin",ios::binary | ios::in);
     if (inputFile.fail()){
        cout << "Unable to open the file!" <<endl;
        exit(EXIT_FAILURE);
     } else{
         cout << "ENTER STUDENT NAME TO SEARCH" <<endl;
         cin.getline(studentName,30);
         while (inputFile.read((char*)&student,sizeof(student))){
            if (strcmp(studentName,student.getStudentName())==0){
                cout << "RECORD FOUND!" <<endl;
                isStudentsDataAvailable = true;
                student.showStudentDetails();
            }
         }
         if (isStudentsDataAvailable == false){
            cout << " No records found in the file " <<endl;
         }
     }
     inputFile.close();
}

void UpdateStudentRecord(){
     fstream inOutFile;
     Student student;
     bool isRecordFound = false;
     int option;
     char studentName[30];
     char studentGender[8];
     int studentAge;
     char studentAddress[40];
     char studentPhone[16];
     inOutFile.open("Student.bin",ios::in | ios::out | ios::binary);
     if (inOutFile.fail()){
        cerr << "Unable to open the file" <<endl;
        exit(EXIT_FAILURE);
     }
     cout << "ENTER STUDENT NAME TO UPDATE" <<endl;
     cin.getline(studentName,30);
     while (inOutFile.read((char*)&student,sizeof(student))){
        if (strcmp(studentName,student.getStudentName())==0){
            isRecordFound = true;
            cout << "\n1.STUDENT NAME    : " << student.getStudentName();
            cout << "\n2.STUDENT GENDER  : " << student.getStudentGender();
            cout << "\n3.STUDENT AGE     : " << student.getStudentAge();
            cout << "\n4.STUDENT ADDRESS : " << student.getStudentAddress();
            cout << "\n5.STUDENT PHONE   : " << student.getStudentPhoneNumber() <<endl <<endl;
            cout << "CHOOSE THE FIELD YOU WANT TO UPDATE" <<endl;
            cin >> option;
            cin.ignore(256,'\n');
            switch (option){
                case 1:
                    cout << "ENTER NEW STUDENT NAME" <<endl;
                    cin.getline(studentName,30);
                    student.setStudentName(studentName);
                    break;
                case 2:
                    cout << "ENTER NEW STUDENT GENDER" <<endl;
                    cin >> studentGender;
                    student.setStudentGender(studentGender);
                    break;
                case 3:
                    cout << "ENTER NEW STUDENT AGE" <<endl;
                    cin >> studentAge;
                    student.setStudentAge(studentAge);
                    break;
                case 4:
                    cout << "ENTER NEW STUDENT EMAIL ADDRESS" <<endl;
                    cin.getline(studentAddress,40);
                    student.setStudentAddress(studentAddress);
                    break;
                case 5:
                    cout << "ENTER NEW STUDENT PHONE NUMBER" <<endl;
                    cin.getline(studentPhone,15);
                    student.setStudentPhoneNumber(studentPhone);
                    break;
                default:
                    cerr << "WRONG OPTION" <<endl;
                    break;
            }
            int position = -1 * sizeof(student);
            inOutFile.seekp(position,ios::cur);
            inOutFile.write((char*)&student,sizeof(student));
            inOutFile.close();
            cout << "Record successfully updated" <<endl;
        }
     }
     if (!isRecordFound){
        cout << "Record not found in the file!" <<endl;
     }
}

void DeleteStudentRecord(){
     ifstream inputFile;
     ofstream outputFile;
     Student student;
     char studentName[30];
     bool isStudentAvailable = false;
     inputFile.open("Student.bin",ios::binary | ios::in);
     outputFile.open("Temp.bin",ios::binary | ios::out | ios::app);
     if (inputFile.fail()){
        cerr << "Unable to open the file!" <<endl;
        exit(EXIT_FAILURE);
     }
     if (outputFile.fail()){
        cerr << "Unable to create a file!" <<endl;
        exit(EXIT_FAILURE);
     }
     cout << "ENTER STUDENT NAME TO DELETE" <<endl;
     cin.getline(studentName,30);
     while (inputFile.read((char*)&student,sizeof(student))){
        if (strcmp(studentName,student.getStudentName())!=0){
            outputFile.write((char*)&student,sizeof(student));
        } else{
            isStudentAvailable = true;
        }
     }
     inputFile.close();
     outputFile.close();
     if (isStudentAvailable){
         remove("Student.bin");
         rename("Temp.bin","Student.bin");
         cout <<studentName << " record successfully deleted" <<endl;
     } else{
         cout << "Student record not found" <<endl;
         remove("Temp.bin");
     }
}

void Menu(){
     int option;
     cout << "____________________WELCOME TO STUDENT RECORD PROGRAM____________________"<<endl <<endl;
     cout << "\t\t[1] ADD STUDENT RECORD" <<endl;
     cout << "\t\t[2] VIEW STUDENT RECORDS" <<endl;
     cout << "\t\t[3] SEARCH STUDENT RECORDS" <<endl;
     cout << "\t\t[4] UPDATE STUDENT RECORD" <<endl;
     cout << "\t\t[5] DELETE STUDENT RECORD" <<endl;
     cout << "\t\t[0] EXIT APPLICATION" <<endl <<endl;
     cout << "\t\tSELECT YOUR OPTION\n\t\t";
     cin >>option;
     cin.ignore(256,'\n');
     system("CLS");
     switch (option){
     case 1:
         AddStudentRecord();
         getch();
         system("CLS");
         Menu();
        break;
     case 2:
         DisplayStudentRecord();
         getch();
         system("CLS");
         Menu();
        break;
     case 3:
         SearchStudentRecord();
         getch();
         system("CLS");
         Menu();
        break;
     case 4:
         UpdateStudentRecord();
         getch();
         system("CLS");
         Menu();
        break;
     case 5:
         DeleteStudentRecord();
         getch();
         system("CLS");
         Menu();
        break;
     case 0:
         exit(EXIT_SUCCESS);
        break;
     default:
         cerr << "WRONG OPTION" <<endl;
        break;
     }
}
