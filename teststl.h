#ifndef TESTSTL_H_INCLUDED
#define TESTSTL_H_INCLUDED
//������
void testitr1() {
    int size=10;
    int *array=new int[size];
    //����ʵ�ֵĵ�����
    for (int i=0;i<size;i++) {
        array[i]=i;
    }
    //����last����ʾ�����е��κ�һ��λ��
    int *last=array+size;
    //ָ��ʵ�ֵ����������
    int *next=array;
    for (;next<last;++next) {
        *next=1;
    }
    //��һ�����������ʵ��
    next=array;
    while (next<last) {
        *next++=1;
    }

//���������
//����Fortran���Ե�Doѭ��
    int *first=array;
    for (int *p=first;p<last;++p) {
        printf("%d\n",*p);
    }

    for (int *p=first;p!=last;++p) {
        printf("%d\n",*p);
    }


}


#endif // TESTSTL_H_INCLUDED
