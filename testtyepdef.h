#ifndef TESTTYEPDEF_H_INCLUDED
#define TESTTYEPDEF_H_INCLUDED
/**
���Ͷ���
��ʽ��
typedef A B;
������A�����B����BΪ�Զ�������
һ�㣺typedef˵���������Դ�д��Ļ��ͷ����ʾ����
!���κ�������typedef��û�д���һ�������ͣ�ֻ��Ϊĳ���Ѵ��ڵ�����������һ���µ�����
!typedef��define������ǰ�߿ɱ����������ͣ��ܴ����ı��滻��Ԥ��������޷��쵽

ʹ��typedef�ĺô���1 ʹ�������������߳���Ŀ���ֲ��  �������������ڻ��������
2 Ϊ�����ṩ���õ��ĵ�
**/
typedef int Length;
typedef char* String;
struct StructA {
};
//֧�ֽṹ��
typedef struct StructA NewType;
//
//!����һ������ָ�룬�������ͺͺ����������һ��
//!��ͬ��һ������
typedef int (*PFI)(char *, char *);
//xxx
//typedef int (*)(char *, char *) PFI2;

void testTypedef() {
}


#endif // TESTTYEPDEF_H_INCLUDED
