#ifndef CH01_H_INCLUDED
#define CH01_H_INCLUDED
//#include<string.h>
/* getline:  read a line into s, return length
limΪ�ַ��������󳤶�
����ʵ�ʶ�ȡ�ĸ���,
��\n
����'\0'
*/
int getline(char s[],int lim) {
    int c, i;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    //�����һ�������ж�
    if (c == '\n') {//�������һ��\n
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
//������\n����
//int getChars(char s[],int lim) {
//    int c, i;
//
//    for (i=0; i <lim && (c=getchar())!=EOF && c!='\n'; ++i)
//        s[i] = c;
//    s[i] = '\0';
//    return i;
//}
//��ӡ���ⳤ�ȵ�һ��
void printArbitaryLongLine() {
//    char buf[11];
    int bufferSize=10;
    char *buf=(char *)malloc((bufferSize+1)*sizeof(char));
//    string str=
    int r=getline(buf,bufferSize);

    while (r>0) {
        //���
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
