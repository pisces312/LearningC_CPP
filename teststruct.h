#ifndef TESTSTRUCT_H_INCLUDED
#define TESTSTRUCT_H_INCLUDED
/**
C中的结构不能有成员函数，只能是变量的集合,不能有权限修饰符
**/
struct Person {
    char name[20];
//    public://
    unsigned long id;
    float salary;
//    void print(){
//    }
};
struct point {
    int x;
    int y;
};
//!结构体中的变量可以是结构体
struct rect {
    struct point pt1;
    struct point pt2;
};

/**
返回结构体的函数
makepoint:  make a point from x and y components
**/
struct point makepoint(int x, int y) {
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
};
/**
结构体作为参数
结构体类型和其他类型参数一样按值传递!!!
**/
/* addpoints:  add two points */
struct point addpoint(struct point p1, struct point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}
/*
判断一个点是否在给定矩形内
ptinrect:  return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rect r) {
    return p.x >= r.pt1.x && p.x < r.pt2.x
           && p.y >= r.pt1.y && p.y < r.pt2.y;
}

void testStruct() {
    //结构体的定义和其变量的定义相结合
    struct {
        double x,y;
    } x,y,z;
//    Person p2;
    //C中，结构变量定义在结构类型名前必须有struct关键字
    //结构体在声明时初始化
    struct Person pr= {"nili",1234,1.2};
    printf("%d\n",pr.id);
    printf("%s\n",pr.name);
    printf("%f\n",pr.salary);
    //!结构体之间不能比较？
    //
    //!关于结构体的大小
    struct {
        char c;
        int i;
    } s1;
    //!实际不是5字节，而是8字节！！！
    printf("%d\n",sizeof(s1));
    //
    struct {
        char c1,c2,c3,c4;
        int i;
    } s2;
    //!也是8字节
    printf("%d\n",sizeof(s2));


    /**
    需要注意的是一般32位C编译器都认为char是8bit，short是16bit，int为32bit，所以node在内存中应该正好是对齐的，也就是 abc这几个成员之间没有空隙。最终结果应该为60503，如果不是，欢迎你告诉我你具体的编译环境以及硬件配置。(和大端、小端相关。LZ注)
    **/
    struct node {
        char a;
        char b;
        short c;
        int d;
    };
    struct node s = { 3, 5, 6, 99 };
    struct node *pt = &s;

    printf("%X\n", *(int*)pt);//60503

}

#endif // TESTSTRUCT_H_INCLUDED
