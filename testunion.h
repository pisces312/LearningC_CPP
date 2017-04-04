#ifndef TESTUNION_H_INCLUDED
#define TESTUNION_H_INCLUDED
/**
!!!在某种意义上，联合也是一个结构，只不过是其所有成员相对于基地址的偏移量为0，结构空间要达到能容纳最“宽”的成员
//
在不同时刻保存不同类型和大小的对象的变量
提供了一种方法，可在但块存储区中管理不同类型的数据，而不需要在程序中嵌入任何依赖于机器的信息
目的：一个单一变量能合法地保存几种类型中的任一种
//
访问方法同结构和类
!同struct的使用一样，union关键字不能省略
!联合可在结构和数组中出现，反之亦然
**/
/**
变量u要足够大以便能保存这三种类型中最大的
这里为4字节
不同的类型要调用不同的变量，整体相当于一个
**/
union u_tag {
    int ival;
    float fval;
    char *sval;
} u;
//
struct {
    char *name;
    int flags;
    int utype;
    union {
        int ival;
        float fval;
        char *sval;
    } u;
} symtab[100];

const int INT=0;
const int FLOAT=1;
const int STRING=2;
void print(int utype,union u_tag u) {
//    int utype=INT;
    if (utype == INT)
        printf("%d\n", u.ival);
    else if (utype == FLOAT)
        printf("%f\n", u.fval);
    else if (utype == STRING)
        printf("%s\n", u.sval);
    else
        printf("bad type %d in utype\n", utype);
}
void testUnionType() {
    printf("%d\n",sizeof(union u_tag));
    //
    u.ival=123;
    print(INT,u);
    u.fval=1.23;
    print(FLOAT,u);
    u.sval="abcd";
    print(STRING,u);
    //!联合一次只能存储一个变量的值，用其余类型赋值会覆盖上次赋的值
    print(INT,u);
    //
    //!可以作为一个整体单元赋值或拷贝
    union u_tag u2=u;
    print(STRING,u2);
    //!一个联合只能用它第一个成员类型的值来初始化
    //???gcc中可以用其他类型
    union u_tag u3={234};//(234);
    print(INT,u3);
    union u_tag u4={"erf"};//(234);
    print(STRING,u4);



}


#endif // TESTUNION_H_INCLUDED
