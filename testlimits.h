#ifndef TESTLIMITS_H_INCLUDED
#define TESTLIMITS_H_INCLUDED
//#include<iostream.h>
#include <limits.h>
#include<stdio.h>
void testLimits() {
    printf("%d\n",CHAR_BIT);//    8 bits in a char
    printf("%d\n",CHAR_MAX);//  UCHAR_MAX or SCHAR_MAX   maximum value of char
    printf("%d\n",CHAR_MIN);//  0 or SCHAR_MIN maximum value of char
    printf("%d\n",INT_MAX);//  32767 maximum value of int
    printf("%d\n",INT_MIN);//  -32767 minimum value of int
    printf("%d\n",LONG_MAX);//  2147483647 maximum value of long
    printf("%d\n",LONG_MIN);//  -2147483647 minimum value of long
    printf("%d\n",SCHAR_MAX);// +127 maximum value of signed char
    printf("%d\n",SCHAR_MIN);// -127 minimum value of signed char
    printf("%d\n",SHRT_MAX);//  +32767 maximum value of short
    printf("%d\n",SHRT_MIN);//  -32767 minimum value of short
    printf("%d\n",UCHAR_MAX);// 255 maximum value of unsigned char
    printf("%d\n",UINT_MAX);//  65535 maximum value of unsigned int
    printf("%d\n",ULONG_MAX);// 4294967295 maximum value of unsigned long
    printf("%d\n",USHRT_MAX);// 65535 maximum value of unsigned short

//  cout<<"short 的值介于"<<numeric_limits<short>::min()
//  <<"至"<<numeric_limits<short>::max()<<endl;
//  cout<<"int 的值介于"<<numeric_limits<int>::min()
//  <<"至"<<numeric_limits<int>::max()<<endl;
//  cout<<"long int 的值介于"<<numeric_limits<long int>::min()
//  <<"至"<<numeric_limits<long int>::max()<<endl;
}


#endif // TESTLIMITS_H_INCLUDED
