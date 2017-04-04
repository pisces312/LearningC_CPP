#ifndef TESTUNION_H_INCLUDED
#define TESTUNION_H_INCLUDED
/**
!!!��ĳ�������ϣ�����Ҳ��һ���ṹ��ֻ�����������г�Ա����ڻ���ַ��ƫ����Ϊ0���ṹ�ռ�Ҫ�ﵽ����������ĳ�Ա
//
�ڲ�ͬʱ�̱��治ͬ���ͺʹ�С�Ķ���ı���
�ṩ��һ�ַ��������ڵ���洢���й���ͬ���͵����ݣ�������Ҫ�ڳ�����Ƕ���κ������ڻ�������Ϣ
Ŀ�ģ�һ����һ�����ܺϷ��ر��漸�������е���һ��
//
���ʷ���ͬ�ṹ����
!ͬstruct��ʹ��һ����union�ؼ��ֲ���ʡ��
!���Ͽ��ڽṹ�������г��֣���֮��Ȼ
**/
/**
����uҪ�㹻���Ա��ܱ�������������������
����Ϊ4�ֽ�
��ͬ������Ҫ���ò�ͬ�ı����������൱��һ��
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
    //!����һ��ֻ�ܴ洢һ��������ֵ�����������͸�ֵ�Ḳ���ϴθ���ֵ
    print(INT,u);
    //
    //!������Ϊһ�����嵥Ԫ��ֵ�򿽱�
    union u_tag u2=u;
    print(STRING,u2);
    //!һ������ֻ��������һ����Ա���͵�ֵ����ʼ��
    //???gcc�п�������������
    union u_tag u3={234};//(234);
    print(INT,u3);
    union u_tag u4={"erf"};//(234);
    print(STRING,u4);



}


#endif // TESTUNION_H_INCLUDED
