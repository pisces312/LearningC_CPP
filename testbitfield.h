#ifndef TESTBITFIELD_H_INCLUDED
#define TESTBITFIELD_H_INCLUDED
/**
C��������unsigned int���ͣ�signed int���ͻ�int���͵�λ�ֶΣ��ֱ��Ϊ�޷���λ�Σ�������λ�ֶκ���ͨλ�ֶΡ�����ͨ�ַ�һ������ͨλ�ֶο����޷��Ż�����š�C99����_Bool���͵�λ�ֶΡ�

!ÿ�����������õ�λ�����ܳ����ñ�����λ��

//
����������
**/
#define KEYWORD2  01
#define EXTRENAL2 02
#define STATIC2   04
//1,10,100
enum { KEYWORD = 01, EXTERNAL = 02, STATIC = 04 };

void testBitField() {

    int flags=0;
//!������ "|"
    flags |= EXTERNAL | STATIC;
    printf("%d\n",flags);
    flags=6;
    //!������ &,~
    flags &= ~(EXTERNAL | STATIC);

    printf("%d\n",flags);
    /**
    ֱ�������ڶ���ͷ����ֶε�����

    **/
    struct {
        //!��λ������Ϊ1bit
        unsigned int is_keyword : 1;
        unsigned int is_extern  : 1;
        unsigned int is_static  : 1;
    } cflags;
    //?4�ֽڣ���μ����С
    printf("%d\n",sizeof(cflags));
    //
    //!һ�������3��unsigned intռ12�ֽ�
    struct bf {
        /**
        ����������һ����������λ�����ڱ������͵�λ��������ʹ����һ�������Ĵ洢λ��
        !!
        ����λ�ֶΡ�

        �ṹ�У������԰���һ������λ�ֶΣ��ṩ���ڳ�Ա֮�����䡣����λ�ֶβ������ã�����ʱ����λ�ֶε��������޷�Ԥ��ġ�


        **/
        //!����32������
//        unsigned int a:36;
        unsigned int a:32;
        //!���Բ�д������
        /**
        ������λ�ֶ�ָ������0�������������壺��ʾ�洢ǰһλ�ֶε����в����ٷ��ø����λ�ֶΡ�
        **/
        unsigned int :0;

        unsigned int b:3;
    };
    struct bf b1;
    b1.a=257; /* 257ռ��9λ */
    printf("%d\n",b1.a); /* ����ȷ���257 */
    printf("%d\n",sizeof(b1));

//
//��׼C���������ڲ��öԶ��Ĳ���Ϊ���뷽ʽ�ļ�����е�Ч��
    struct S {
        unsigned a:3;
        signed b:3;
        int c:3;
    }t = {-1, -1, -1};
    printf("%d,%d,%d\n",t.a,t.b,t.c);
    //!3+3+3��9λ��ֻ��Ҫռ��һ���洢��Ԫ���ɣ���ֻҪ4�ֽ�
    printf("%d\n",sizeof(t));
//

//        ��ʱt.a,t.b,t.c��ֵ�ֱ�Ϊ7��-1��-1��
//
//
    struct bf2 {
        unsigned int a:2;
        //��һ���洢��Ԫ
        unsigned int :0;
        unsigned int b:3;
        //��һ���洢��Ԫ
        unsigned int :0;
        unsigned int c:3;


    };
    printf("%d\n",sizeof(struct bf2));


}


#endif // TESTBITFIELD_H_INCLUDED
