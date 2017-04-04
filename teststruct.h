#ifndef TESTSTRUCT_H_INCLUDED
#define TESTSTRUCT_H_INCLUDED
/**
C�еĽṹ�����г�Ա������ֻ���Ǳ����ļ���,������Ȩ�����η�
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
//!�ṹ���еı��������ǽṹ��
struct rect {
    struct point pt1;
    struct point pt2;
};

/**
���ؽṹ��ĺ���
makepoint:  make a point from x and y components
**/
struct point makepoint(int x, int y) {
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
};
/**
�ṹ����Ϊ����
�ṹ�����ͺ��������Ͳ���һ����ֵ����!!!
**/
/* addpoints:  add two points */
struct point addpoint(struct point p1, struct point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}
/*
�ж�һ�����Ƿ��ڸ���������
ptinrect:  return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rect r) {
    return p.x >= r.pt1.x && p.x < r.pt2.x
           && p.y >= r.pt1.y && p.y < r.pt2.y;
}

void testStruct() {
    //�ṹ��Ķ����������Ķ�������
    struct {
        double x,y;
    } x,y,z;
//    Person p2;
    //C�У��ṹ���������ڽṹ������ǰ������struct�ؼ���
    //�ṹ��������ʱ��ʼ��
    struct Person pr= {"nili",1234,1.2};
    printf("%d\n",pr.id);
    printf("%s\n",pr.name);
    printf("%f\n",pr.salary);
    //!�ṹ��֮�䲻�ܱȽϣ�
    //
    //!���ڽṹ��Ĵ�С
    struct {
        char c;
        int i;
    } s1;
    //!ʵ�ʲ���5�ֽڣ�����8�ֽڣ�����
    printf("%d\n",sizeof(s1));
    //
    struct {
        char c1,c2,c3,c4;
        int i;
    } s2;
    //!Ҳ��8�ֽ�
    printf("%d\n",sizeof(s2));


    /**
    ��Ҫע�����һ��32λC����������Ϊchar��8bit��short��16bit��intΪ32bit������node���ڴ���Ӧ�������Ƕ���ģ�Ҳ���� abc�⼸����Ա֮��û�п�϶�����ս��Ӧ��Ϊ60503��������ǣ���ӭ������������ı��뻷���Լ�Ӳ�����á�(�ʹ�ˡ�С����ء�LZע)
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
