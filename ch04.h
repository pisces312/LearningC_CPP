#ifndef CH04_H_INCLUDED
#define CH04_H_INCLUDED
#include "ch04_4_2.h"
#include "calculate.h"
//#include "逆波兰计算器.h"
//BruteForce算法
/* strindex:  return index of t in s, -1 if none
t在s中的位置
*/
int strindex(char s[], char t[]) {
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}
/* atof:  convert string s to double */
//!将整数小数一起看待，得到一个大整数，最后除以小数位数
double atof2(char s[]) {
    //power用于统计小数位数
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)  /* skip white space */
        ;
    //符号
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    //
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    //跳过.
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    return sign * val / power;
}
//!可处理科学计数法
double atof3(char s[]) {
    //power用于统计小数位数
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)  /* skip white space */
        ;
    //符号
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    //
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    //跳过.
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    //
    val/=power;
    //
    if (s[i]=='e'||s[i]=='E') {
        i++;
        //标记指数是否为正数
        int flag=1;
        if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            flag=0;
            i++;
        }
        int t=0;
        for (; isdigit(s[i]); i++) {
            t=t*10+(s[i]-'0');
        }
        power=1.0;
        printf("%d\n",t);
        for(i=0;i<t;i++){
            power*=10;
        }
        if (flag) {
            val*=power;
        } else {
            val/=power;
        }
    }

    return sign * val;
}
//namespace ch04 {
void testCh04() {
    char s[]="agasdfewab";
    char t[]="ab";
    int index=strindex(s,t);
    printf("%d\n",index);
    //
    char dNumChar[]="123.432";
    double d=atof2(dNumChar);
    printf("%f\n",d);
    //
    char dNumChar2[]="123.432e-5";
    d=atof3(dNumChar2);
    printf("%.10f\n",d);
    //
    ch04_4_2();
    //
    polishCalculator();

}
//};
#endif // CH04_H_INCLUDED
