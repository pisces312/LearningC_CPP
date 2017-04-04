#ifndef TESTTIME_H_INCLUDED
#define TESTTIME_H_INCLUDED
#include<time.h>
// Pauses for a specified number of milliseconds.
void sleep( clock_t wait ) {
    clock_t goal;
    goal = wait + clock();
    while ( goal > clock() )
        ;
}
//struct tm;
//����ʱ�������ʱ����ܲ�ͬ
void testTimeHeader() {
    //���ص������ĳ����Կ�ʼִ�е�Ŀǰ��ռ�ô����ʱ��
    //���ܻ᷵��0
    clock_t c=clock();
    printf("%d\n",c);
//    sleep();
    long    i = 6000000L;
    clock_t start, finish;
    double  duration;
    int seconds=0;

    // Delay for a specified time.
    printf( "Delay for %d seconds\n",seconds );
    //!��clock()/CLOCKS_PER_SEC����Ϊ��λ
    sleep( (clock_t)seconds * CLOCKS_PER_SEC );
    printf( "Done!\n" );

    // Measure the duration of an event.
    printf( "Time to do %ld empty loops is ", i );
    start = clock();
    while ( i-- )
        ;
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%2.1f seconds\n", duration );
    //
    //
    c=clock();
    printf("%d\n",c);
    //
    //
    time_t t=time(NULL);
    printf("%d\n",t);
//    sleep(1000);
//!��������ʱ��Ĳ�ֵ������ֵ
    double dTime=difftime(time(NULL),t);
    printf("%f\n",dTime);
    //

    //
    time_t the_time;
    (void) time (&the_time);
    struct tm *tmPtr;
    //!����ʱ��ת��Ϊ����ʱ��
    tmPtr=localtime(&the_time);
    printf("hour=%d\n",tmPtr->tm_hour);
    printf("��ʱ��=%d\n",tmPtr->tm_isdst);
    printf("day=%d\n",tmPtr->tm_mday);
    printf("minute=%d\n",tmPtr->tm_min);
    printf("month=%d\n",tmPtr->tm_mon);
    printf("second=%d\n",tmPtr->tm_sec);
    //������������������
    printf("week day(0~6)=%d\n",tmPtr->tm_wday);
    printf("year day(0~365)=%d\n",tmPtr->tm_yday);
    //��1900�꿪ʼ������ʱ��
    printf("year=%d\n",tmPtr->tm_year+1900);
    //
    printf("%s\n",asctime(tmPtr));
    time_t time2=mktime(tmPtr);
    printf("time_t time=%d\n",time2);
    //
    //!ctime������ʱ��ת��Ϊ����ʱ��
    printf("%s\n",ctime(&time2));
    //
    struct tm *tmPtr2=gmtime(&time2);
    printf("%s\n",asctime(tmPtr2));
//
//
//����Զ����ʽ��ʱ���ַ���
size_t smax=100;
char *s=(char*)malloc(sizeof(char)*smax);
size_t time3=strftime(s,smax,"%A %c",tmPtr);
printf("%s\n",s);



}


#endif // TESTTIME_H_INCLUDED
