#ifndef LINUXMKTIME_H_INCLUDED
#define LINUXMKTIME_H_INCLUDED
#include <time.h>		// ʱ��ͷ�ļ��������˱�׼ʱ�����ݽṹtm ��һЩ����ʱ�亯��ԭ�͡�
#include <stdio.h>
namespace Linux {
    /*
     * �ⲻ�ǿ⺯�����������ں�ʹ�á�������ǲ�����С��1970 �����ݵȣ����ٶ�һ�о���������
     * ͬ����ʱ������TZ ����Ҳ�Ⱥ��ԡ�����ֻ�Ǿ����ܼ򵥵ش������⡣������ҵ�һЩ�����Ŀ⺯��
     * ����������Ϊminix ��ʱ�亯���ǹ����ģ���
     * ���⣬�Һ��Ǹ�����1970 �꿪ʼ���� - �ѵ����ǾͲ���ѡ���һ�����꿪ʼ���Һ޸����������
     * ����̻ʡ����̣���ʲô�����ں������Ǹ�Ƣ��������ˡ�
     */
    #define MINUTE 60		// 1 ���ӵ�������
    #define HOUR (60*MINUTE)	// 1 Сʱ��������
    #define DAY (24*HOUR)		// 1 ���������
    #define YEAR (365*DAY)		// 1 ���������

    /* interestingly, we assume leap-years */
    /* ��Ȥ�������ǿ��ǽ������� */
// ��������Ϊ���ޣ�������ÿ���¿�ʼʱ������ʱ�����顣
    static int month[12] = {
        0,
        DAY * (31),
        DAY * (31 + 29),
        DAY * (31 + 29 + 31),
        DAY * (31 + 29 + 31 + 30),
        DAY * (31 + 29 + 31 + 30 + 31),
        DAY * (31 + 29 + 31 + 30 + 31 + 30),
        DAY * (31 + 29 + 31 + 30 + 31 + 30 + 31),
        DAY * (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31),
        DAY * (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30),
        DAY * (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31),
        DAY * (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30)
    };

// �ú��������1970 ��1 ��1 ��0 ʱ�𵽿������վ�������������Ϊ����ʱ�䡣
    long
    kernel_mktime (struct tm *tm) {
        long res;
        int year;

        year = tm->tm_year - 70;	// ��70 �굽���ھ���������(2 λ��ʾ��ʽ)��
        // ��˻���2000 �����⡣
        /* magic offsets (y+1) needed to get leapyears right. */
        /* Ϊ�˻����ȷ����������������Ҫ����һ��ħ��ƫֵ(y+1) */
        res = YEAR * year + DAY * ((year + 1) / 4);	// ��Щ�꾭��������ʱ�� + ÿ������ʱ��1 ��
        res += month[tm->tm_mon];	// ������ʱ�䣬�ڼ��ϵ��굽����ʱ��������
        /* and (y+2) here. If it wasn't a leap-year, we have to adjust */
        /* �Լ�(y+2)�����(y+2)�������꣬��ô���Ǿͱ�����е���(��ȥһ�������ʱ��)�� */
        if (tm->tm_mon > 1 && ((year + 2) % 4))
            res -= DAY;
        res += DAY * (tm->tm_mday - 1);	// �ټ��ϱ��¹�ȥ������������ʱ�䡣
        res += HOUR * tm->tm_hour;	// �ټ��ϵ����ȥ��Сʱ��������ʱ�䡣
        res += MINUTE * tm->tm_min;	// �ټ���1 Сʱ�ڹ�ȥ�ķ�����������ʱ�䡣
        res += tm->tm_sec;		// �ټ���1 �������ѹ���������
        return res;			// �����ڴ�1970 ����������������ʱ�䡣
    }
    //
    void test() {
        time_t the_time;
        (void) time (&the_time);
        struct tm *tmPtr;
        //!����ʱ��ת��Ϊ����ʱ��
        tmPtr=localtime(&the_time);
        //
        printf("%d\n",kernel_mktime(tmPtr));

    }
};


#endif // LINUXMKTIME_H_INCLUDED
