#ifndef TESTTYEPDEF_H_INCLUDED
#define TESTTYEPDEF_H_INCLUDED
/**
类型定义
格式：
typedef A B;
把类型A定义成B，即B为自定义类型
一般：typedef说明的类型以大写字幕开头，以示区别
!在任何意义上typedef都没有创建一个新类型，只是为某个已存在的类型增加了一个新的名称
!typedef与define的区别，前者可被编译程序解释，能处理文本替换，预处理程序无法办到

使用typedef的好处：1 使程序参数化，提高程序的可移植性  数据类型依赖于机器的情况
2 为程序提供更好的文档
**/
typedef int Length;
typedef char* String;
struct StructA {
};
//支持结构体
typedef struct StructA NewType;
//
//!定义一个函数指针，函数类型和函数名结合在一起
//!不同于一般类型
typedef int (*PFI)(char *, char *);
//xxx
//typedef int (*)(char *, char *) PFI2;

void testTypedef() {
}


#endif // TESTTYEPDEF_H_INCLUDED
