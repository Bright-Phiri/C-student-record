#ifndef STUDENT_H
#define STUDENT_H


class Student
{
    public:
        Student();
        ~Student();
        void getStudentDetails();
        void showStudentDetails();
        char* getStudentName();
        void setStudentName(char*);
        char* getStudentGender();
        void setStudentGender(char*);
        int getStudentAge();
        void setStudentAge(int);
        char* getStudentAddress();
        void setStudentAddress(char*);
        char* getStudentPhoneNumber();
        void setStudentPhoneNumber(char*);
    private:
        char studentName[30];
        char studentGender[8];
        int studentAge;
        char studentAddress[40];
        char studentPhoneNumber[16];
};

#endif // STUDENT_H
