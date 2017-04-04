#ifndef CH01_H_INCLUDED
#define CH01_H_INCLUDED
//#include<string.h>
/* getline:  read a line into s, return length
lim为字符数组的最大长度
返回实际读取的个数,
算\n
不算'\0'
*/
int getline(char s[],int lim) {
    int c, i;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    //对最后一个单独判断
    if (c == '\n') {//补上最后一个\n
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
//遇到即\n返回
//int getChars(char s[],int lim) {
//    int c, i;
//
//    for (i=0; i <lim && (c=getchar())!=EOF && c!='\n'; ++i)
//        s[i] = c;
//    s[i] = '\0';
//    return i;
//}
//打印任意长度的一行
void printArbitaryLongLine() {
//    char buf[11];
    int bufferSize=10;
    char *buf=(char *)malloc((bufferSize+1)*sizeof(char));
//    string str=
    int r=getline(buf,bufferSize);

    while (r>0) {
        //相等
//        printf("%d\n",r);
//        printf("%d\n",strlen(buf));
        printf("%s",buf);
        if (buf[r-1]=='\n') {
            break;
        }
        r=getline(buf,bufferSize);

    }

}
void testCh01() {
    char s[10];
    int lim=10;
    int c=getline(s,lim);
    printf("%d\n",c);
}


#endif // CH01_H_INCLUDED
