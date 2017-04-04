#ifndef TESTBITFIELD_H_INCLUDED
#define TESTBITFIELD_H_INCLUDED
/**
C语言允许unsigned int类型，signed int类型或int类型的位字段，分别称为无符号位段，带符号位字段和普通位字段。和普通字符一样，普通位字段可以无符号或带符号。C99允许_Bool类型的位字段。

!每个变量所设置的位数不能超过该变量的位数

//
可用于掩码
**/
#define KEYWORD2  01
#define EXTRENAL2 02
#define STATIC2   04
//1,10,100
enum { KEYWORD = 01, EXTERNAL = 02, STATIC = 04 };

void testBitField() {

    int flags=0;
//!加条件 "|"
    flags |= EXTERNAL | STATIC;
    printf("%d\n",flags);
    flags=6;
    //!减条件 &,~
    flags &= ~(EXTERNAL | STATIC);

    printf("%d\n",flags);
    /**
    直接在字内定义和访问字段的能力

    **/
    struct {
        //!将位宽设置为1bit
        unsigned int is_keyword : 1;
        unsigned int is_extern  : 1;
        unsigned int is_static  : 1;
    } cflags;
    //?4字节，如何计算大小
    printf("%d\n",sizeof(cflags));
    //
    //!一般情况下3个unsigned int占12字节
    struct bf {
        /**
        ！！！！当一个变量设置位数大于本身类型的位数，将会使用下一个变量的存储位置
        !!
        无名位字段。

        结构中，还可以包括一个无名位字段，提供相邻成员之间的填充。无名位字段不能引用，运行时无名位字段的内容是无法预测的。


        **/
        //!超过32，错误
//        unsigned int a:36;
        unsigned int a:32;
        //!可以不写变量名
        /**
        对无名位字段指定长度0，具有特殊意义：表示存储前一位字段的区中不能再放置更多的位字段。
        **/
        unsigned int :0;

        unsigned int b:3;
    };
    struct bf b1;
    b1.a=257; /* 257占用9位 */
    printf("%d\n",b1.a); /* 能正确输出257 */
    printf("%d\n",sizeof(b1));

//
//标准C语言声明在采用对二的补码为编码方式的计算机中的效果
    struct S {
        unsigned a:3;
        signed b:3;
        int c:3;
    }t = {-1, -1, -1};
    printf("%d,%d,%d\n",t.a,t.b,t.c);
    //!3+3+3共9位，只需要占用一个存储单元即可，即只要4字节
    printf("%d\n",sizeof(t));
//

//        此时t.a,t.b,t.c的值分别为7，-1，-1。
//
//
    struct bf2 {
        unsigned int a:2;
        //换一个存储单元
        unsigned int :0;
        unsigned int b:3;
        //换一个存储单元
        unsigned int :0;
        unsigned int c:3;


    };
    printf("%d\n",sizeof(struct bf2));


}


#endif // TESTBITFIELD_H_INCLUDED
