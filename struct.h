#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include<iostream>
using namespace std;
//�ṹ��ļ̳�
struct BaseStruct{};
struct SubStruct:public BaseStruct{};
//

struct Person{
    //public://��ʡ��
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
    //�ṹ��ĳ�ʼ����ֵ
    Person pr={"nili",1234,1.2};
    cout<<pr.id<<endl;
    cout<<pr.name<<endl;
    cout<<pr.salary<<endl;
    cout<<"sizeof(Person)="<<sizeof(Person)<<endl;
    //��ͬ�ṹ���ı��������໥��ֵ
    Person pr2=pr;
    cout<<pr2.name<<endl;
    //�Խṹ�����鸳ֵ��δ��ֵ�ľ�Ϊ��
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
