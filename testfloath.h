#ifndef TESTFLOATH_H_INCLUDED
#define TESTFLOATH_H_INCLUDED
#include<float.h>
/**
浮点数的极值
**/
void testFloatHeader() {
    printf("%d\n",FLT_RADIX);//  2 radix of exponent, representation, e.g., 2, 16
    printf("%d\n",FLT_ROUNDS);//   floating-point rounding mode for addition
    printf("%d\n",FLT_DIG);//  6 decimal digits of precision
    printf("%f\n",FLT_EPSILON);//  1E-5 smallest number x such that 1.0+x != 1.0
    printf("%d\n",FLT_MANT_DIG);//    number of base FLT_RADIX in mantissa
    printf("%d\n",FLT_MAX);//  1E+37   maximum floating-point number
    printf("%d\n",FLT_MAX_EXP);//   maximum n such that FLT_RADIXn-1 is representable
    printf("%f\n",FLT_MIN);//  1E-37 minimum normalized floating-point number
    printf("%d\n",FLT_MIN_EXP);//   minimum n such that 10n is a normalized number
    printf("%d\n",DBL_DIG);//  10 decimal digits of precision
    printf("%f\n",DBL_EPSILON);//  1E-9 smallest number x such that 1.0+x != 1.0
    printf("%d\n",DBL_MANT_DIG);//  number of base FLT_RADIX in mantissa
    //!最大的double
    printf("%d\n",DBL_MAX);//  1E+37 maximum double floating-point number
    printf("%d\n",DBL_MAX_EXP);//   maximum n such that FLT_RADIXn-1 is representable
    //!绝对值最小的正数
    printf("%f\n",DBL_MIN);//  1E-37 minimum normalized double floating-point number
    printf("%d\n",DBL_MIN_EXP);//   minimum n such that 10n is a normalized number



}


#endif // TESTFLOATH_H_INCLUDED
