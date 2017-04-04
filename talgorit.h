#ifndef TALGORIT_H_INCLUDED
#define TALGORIT_H_INCLUDED
#include<list>
#include<iostream>
#include<algorithm>
#include<assert.h>
#include<ctype.h>
#include<string.h>
#include<functional>
using namespace std;
//
//
equal_to<char> equf;
//!Ĭ�ϵ�ν�ʣ�С��ν��
less<char> lessf;
//less_equal

//

//��������
//f(x,y)�������smaller_int��������ĳ�Ա����
struct smaller_int {
    bool operator()(int x,int y) const {
        return (x<y);
    }
}f;
//���ں���ָ��
bool is_smaller_int(int x,int y) {
    return (x<y);
}
//��һ
template<class FwdIt>
FwdIt smallest(FwdIt first, FwdIt last) {
    return smallest(first,last,smaller_int());
}
//
//template<class FwdIt>
//FwdIt smallest2(FwdIt first, FwdIt last){
//    return smallest(first,last,f());
//}
//
//Pred��ʾν���࣬�������ṩһ�����ʽ
template<class FwdIt,class Pred>
FwdIt smallest(FwdIt first, FwdIt last,Pred pr) {
    //�洢��Сֵ�����λ��
    FwdIt r=first;
    FwdIt t=r;
    for (t++;t!=last;t++) {
        if (pr(*t,*r)) {
            r=t;
        }
    }
    return r;
}
//����
int get_smallest(int *first,int *last) {
    return (*smallest(first,last,smaller_int()));
}
//����
//is_smaller_intǰ��&��ѡ
int get_smallest2(int *first,int *last) {
    return (*smallest(first,last,&is_smaller_int));
}
int get_smallest3(int *first,int *last) {
    return (*smallest(first,last,is_smaller_int));
}
//
namespace mystll {
    template<class FwdIt> inline
    //���ص�һ�����ڵ�ӵ��ͬ��Ԫ�ص�ǰһ��Ԫ�ص�λ��
    FwdIt adjacent_find(FwdIt F,FwdIt L) {
        //Fb��F�ֱ𱣴�����������ڵ�����λ��
        for (FwdIt Fb;(Fb=F)!=L&&++F!=L;)
            if (*Fb==*F)
                return (Fb);
        return (L);
    }
    //
    template<class BidIt,class Pr>inline
    //����ҿ�����
    bool next_permutation(BidIt F,BidIt L,Pr P) {
        //L����
        //
        //��֤������������������Ԫ��
        BidIt I=L;
        //F==L���ų�����ֹλ����ȣ�����Ԫ�ص����
        //F==-I���ų���һ��Ԫ�أ�����һ��Ԫ��λ�ú����һ��Ԫ��λ����ȵ����
        if (F==L||F==-I)
            return false;
        //
        //
        for (;;) {
            BidIt Ip=I;
            //������Ԫ�رȽ�
            if (P(*--I,*Ip)) {
                //�൱�ڽ���һ������
                BidIt J=L;
                for (;!P(*I,*--J););
                std::iter_swap(I,J);
                //
                std::reverse(Ip,L);
                return true;
            }
            if (I==F) {
                std::reverse(F,L);
                return false;
            }
        }
    }

};
void testAlgorithm2() {
    list<int> intList;
    intList.push_back(10);
    intList.push_back(2);
    intList.push_back(2);
    intList.push_back(1);
    intList.push_back(5);
    list<int>::iterator a=smallest(intList.begin(),intList.end());
    cout<<(*a)<<endl;
    //
    //
    int *first=new int[5];
    first[0]=39;
    first[1]=4;
    first[2]=9;
    first[3]=6;
    first[4]=2;
    int *last=first+5;
    int result=get_smallest(first,last);
    cout<<result<<endl;
    result=get_smallest2(first,last);
    cout<<result<<endl;
    result=get_smallest3(first,last);
    cout<<result<<endl;
    //
    list<int>::iterator b=mystll::adjacent_find(intList.begin(),intList.end());
    cout<<(*b)<<endl;
}
//���Խ��Ϊһ��Ԫ�صĺ���
void test_single(char *first,char *last) {
    //!�Ƚϵ�������Ԫ��
    assert(max('0','2')=='2');
    assert(max('0','2',lessf)=='2');
    //
    //
    assert(min('0','2')=='0');
    assert(min('0','2',lessf)=='0');
    //
//    strcpy(first,"abcdefg");
//����ֵ
    swap(first[0],first[1]);
    assert(strcmp(first,"bacdefg")==0);
    //����λ��
    iter_swap(&first[0],&first[1]);
    assert(strcmp(first,"abcdefg")==0);
}
//
//���Բ���
void test_find(char *first,char *last) {
    //cc
    strcpy(first,"abccefg");
    //
    //ȡ�����еļ�ֵ
    assert(*max_element(first,last)=='g');
    assert(*max_element(first,last,lessf)=='g');
    //
    assert(*min_element(first,last)=='a');
    assert(*min_element(first,last,lessf)=='a');
    //ǰ��������Ϊ��һ������������ʼ�ͽ��������һ��Ϊ�ڶ����������Ŀ�ʼ
    //!�Ƚ����е���ȣ����һ��������Ϊ��һ����ǰ׺Ҳ�ж�Ϊ���
    //���Ƚϵĸ���Ϊlast-first��

    assert(equal(first,last,first));
    assert(equal(first,last,first,equf));
    //
    char *t=new char[12];
    strcpy(t,"abccefghijkl");
    assert(equal(first,last,t));
    //
    //ǰ��������Ϊ��һ������������ʼ�ͽ�����������Ϊ�ڶ�����
    //�Ƚϵĸ���������������Ԫ�ظ����ٵľ���
    //!�Ƚ�һ�������Ƿ�������һ������ǰ��
    //!�����ں������У�һ������ĳ��λ�ã�����Ԫ�ش���ǰ�������е�����Ԫ��
    //!����һ����������һ������ǰ׺�Ҳ���ȫ��ȵ��������Ȼǰ׺����������һ������ǰ
    assert(lexicographical_compare(first,last-1,first,last));
    assert(lexicographical_compare(first,last-2,first,last,lessf));
    //!����������ȫ��ȣ��ұȽϵ���ֹ����ȣ����ֳܷ�ǰ�󣬷���false
    assert(!lexicographical_compare(first,last,first,last));
//
//�����������е�һ����ƥ���λ�ã�������������ȫ��ȵ����бȽϣ���Ȼ���ص�����ֹλ��
    assert(mismatch(first,last,first).second==last);
    assert(mismatch(first,last,first,equf).second==last);
//

//!�������в���һ��Ԫ��
//���ص�һ��ƥ���Ԫ�ص�λ��
    assert(find(first,last,'c')==first+2);
//!bind2ndΪһ��ν�ʣ����еĵ�һ������Ҳ��һ��ν��
    assert(find_if(first,last,bind2nd(equf,'c'))==first+2);
//
//��������ȵ�Ԫ�صĵ�һ��λ��
    assert(adjacent_find(first,last)==first+2);
    assert(adjacent_find(first,last,equf)==first+2);
//
    assert(count(first,last,'c')==2);
    assert(count_if(first,last,bind2nd(equf,'c'))==2);
    //
    //
//����һ�������м��һ�����е�һ�γ��ֵĵط�
//!ǰ��������ȷ������һ�����С�������������ȷ���������൱�ڱ����ҵ�������
//����"abccefg"�д�λ��2������"ccefg"
//!�൱���������е�λ��indexOf
    assert(search(first,last,first+2,last)==first+2);
    assert(search(first,last,first+2,last,equf)==first+2);
//!���ҵ�һ����������n��ĳԪ�ص�λ��
//����2��ʾcҪ��������
    assert(search_n(first,last,2,'c')==first+2);
    assert(search_n(first,last,2,'c',equf)==first+2);
    //
    //���һ�������������ֵĵط�
    //!��search���Ӧ
    assert(find_end(first,last,first+2,last)==first+2);
    assert(find_end(first,last,first+2,last,equf)==first+2);
    //!�����һ�������е�����Ԫ����ǰһ�������е�һ�γ��ֵ�λ��
    //
    assert(find_first_of(first,last,first+2,last)==first+2);
    assert(find_first_of(first,last,first+2,last,equf)==first+2);
    //
    //!find_first_of��search����
    char c1[]="abcdefg";
    char c2[]="udio";
    assert(find_first_of(c1,c1+7,c2,c2+4)==c1+3);
    assert(find_first_of(c1,c1+7,c2,c2+4,equf)==c1+3);
    //
    //



}
//
//���������ຯ��
size_t gen_count=0;
void count_c(char ch){
    if(ch=='c')
    ++gen_count;
}
char gen_x(){
    return 'x';
}
void test_generate(char *first,char* last,char * dest){
}
void testAlgorithm() {
    char buf[]="abcdefg";
    char dest[]="1234567";
    char *first=buf,*last=buf+7;
    test_single(first,last);
    test_find(first,last);

}


#endif // TALGORIT_H_INCLUDED
