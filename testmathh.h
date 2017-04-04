#ifndef TESTMATHH_H_INCLUDED
#define TESTMATHH_H_INCLUDED
#include<math.h>
void testMathHeader() {
//    The header <math.h> declares mathematical functions and macros.
//The macros EDOM and ERANGE (found in <errno.h>) are non-zero integral constants that are used to signal domain and range errors for the functions; HUGE_VAL is a positive double value. A domain error occurs if an argument is outside the domain over which the function is defined. On a domain error, errno is set to EDOM; the return value is implementation-defined. A range error occurs if the result of the function cannot be represented as a double. If the result overflows, the function returns HUGE_VAL with the right sign, and errno is set to ERANGE. If the result underflows, the function returns zero; whether errno is set to ERANGE is implementation-defined.
//
//In the following table, x and y are of type double, n is an int, and all functions return double. Angles for trigonometric functions are expressed in radians.

//printf("%f\n",sin(x));//  sine of x
//cos(x)  cosine of x
//tan(x)  tangent of x
//asin(x)  sin-1(x) in range [-pi/2,pi/2], x in [-1,1].
//acos(x)  cos-1(x) in range [0,pi], x in [-1,1].
//atan(x)  tan-1(x) in range [-pi/2,pi/2].
//atan2(y,x) tan-1(y/x) in range [-pi,pi].
//sinh(x)  hyperbolic sine of x
//cosh(x)  hyperbolic cosine of x
//tanh(x)  hyperbolic tangent of x
//exp(x)  exponential function ex
//log(x)  natural logarithm ln(x), x>0.
//log10(x)  base 10 logarithm log10(x), x>0.
//pow(x,y)  xy. A domain error occurs if x=0 and y<=0, or if x<0 and y is not an integer.
//sqrt(x)  sqare root of x, x>=0.
//
    double d=10.2;
//����ȡ��!!����double
    printf("%f\n",ceil(d));//  smallest integer not less than x, as a double.
//����ȡ��
    printf("%f\n",floor(d));//  largest integer not greater than x, as a double.
//
//fabs(x)  absolute value |x|
//ldexp(x,n) x*2n
//frexp(x, int *ip) splits x into a normalized fraction in the interval [1/2,1) which is returned, and a power of 2, which is stored in *exp. If x is zero, both parts of the result are zero.
//modf(x, double *ip) splits x into integral and fractional parts, each with the same sign as x. It stores the integral part in *ip, and returns the fractional part.
//fmod(x,y) floating-point remainder of x/y, with the same sign as x. If y is zero, the result is implementation-defined.


}


#endif // TESTMATHH_H_INCLUDED
