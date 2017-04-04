#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include<iostream>
using namespace std;
//结构体的继承
struct BaseStruct{};
struct SubStruct:public BaseStruct{};
//

struct Person{
    //public://可省略
    char name[20];
    unsigned long id;
    float salary;
};
struct Employee{
    public:
    char name[20];
    unsigned long id;
    float salary;
    void print(){
        cout<<name<<endl;
    }
};
void testStruct(){
    //结构体的初始化赋值
    Person pr={"nili",1234,1.2};
    cout<<pr.id<<endl;
    cout<<pr.name<<endl;
    cout<<pr.salary<<endl;
    cout<<"sizeof(Person)="<<sizeof(Person)<<endl;
    //相同结构名的变量可以相互赋值
    Person pr2=pr;
    cout<<pr2.name<<endl;
    //对结构体数组赋值，未赋值的均为空
    Person allone[6]={
        {"jone",12345,339.0},
        {"jone",12345,339.0},
        {"jone",12345,339.0},
        {"jone",12345,339.0},
//        {"jone",12345,339.0},
        {"jone",12345,339.0}
    };
    cout<<"abcde\n";
    cout<<allone[5].id<<endl;
    cout<<allone[5].name<<endl;
    //
    struct SubStruct substruct;


}


#endif // STRUCT_H_INCLUDED
