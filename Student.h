#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <iostream.h>
#include <string.h>
class StudentID {
    public:
    StudentID(int id=0) {
        value=id;
        cout <<"Assigning student id " <<value <<endl;
    }
    ~StudentID() {
        cout <<"Destructing id " <<value <<endl;
    }
    protected:
    int value;
};

class Student {
    public:
    Student(char* pName="no name",int ssID=0):id(ssID) {
        cout <<"Constructing student " <<pName <<endl;
        strncpy(name,pName,sizeof(name));
        name[sizeof(name)-1]='\n';
    }
    protected:
    char name[20];
    StudentID id;
};

void testStudent() {
    Student s("Randy",9818);
    Student t("Jenny");
}


#endif // STUDENT_H_INCLUDED
