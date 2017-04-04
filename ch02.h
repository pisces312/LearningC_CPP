#ifndef CH02_H_INCLUDED
#define CH02_H_INCLUDED
/* atoi:  convert s to integer */
//namespace ch02 {
    int atoi2(char s[]) {
        int i, n;

        n = 0;
        for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
            n = 10 * n + (s[i] - '0');
        return n;
    }
    void testCast() {
        int a=-1L;
        int b=1U;
        printf("%d\n",a<b);
        long c=-1L;
        unsigned long d=1UL;
        printf("%d\n",c<d);
    }
    /* squeeze:  delete all c from s
    仅使用了原始的空间，没有使用新数组
    因为删除后的字符串的每一位一定比原来的位置靠前，
    所以用同一个数组不会影响到后面的位置
    */
    void squeeze(char s[], int c) {
        int i, j;

        for (i = j = 0; s[i] != '\0'; i++)
            if (s[i] != c)
                s[j++] = s[i];
        s[j] = '\0';
    }
    /* strcat:  concatenate t to end of s; s must be big enough */
    void strcat2(char s[], char t[]) {
        int i, j;

        i = j = 0;
        while (s[i] != '\0') /* find end of s */
            i++;
        while ((s[i++] = t[j++]) != '\0') /* copy t */
            ;
    }
//第0位在最右边
    /* getbits:  get n bits from position p */
    unsigned getbits(unsigned x, int p, int n) {
        return (x >> (p+1-n)) & ~(~0 << n);
    }

    void testExpressionType() {
        int n=-1;
        double f=1.0;
        printf("%d\n",sizeof(n>0?f:n));
    }
    void testCh02() {
//    printf("%d\n",1+2*3);//7 9
//    printf("%d\n",5*2+3);//13 25
        //
//    testExpressionType();
//    int x=7;
//    x&=x-1;
        //
//    printf("%d\n",bitcountEx(7));
        //
//    printf("%d\n",bitcount(7));
        //
//    printf("%d\n",sizeof(~((unsigned long)0)));
        //
//    printf("%d\n",sizeof(unsigned));
        //

//    char s[]="gasdfaweghadfj";
//    squeeze(s,'a');
//    printf("%s\n",s);
//    printf("%d\n",atoi2("123"));
//


    }
//};



#endif // CH02_H_INCLUDED
