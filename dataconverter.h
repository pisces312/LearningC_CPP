#ifndef DATACONVERTER_H_INCLUDED
#define DATACONVERTER_H_INCLUDED
namespace DataConverter {
    //二维数组，非闰年和闰年两种情况
    static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };

    /* day_of_year:  set day of year from month & day
    将xxxx年x月x日，转换为该年中的第几天
    */
    int day_of_year(int year, int month, int day) {
        int i, leap;
        leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
        for (i = 1; i < month; i++)
            day += daytab[leap][i];
        return day;
    }

    /* month_day:  set month, day from day of year
    将某年中第几天转换为某月某日
    */
    void month_day(int year, int yearday, int *pmonth, int *pday) {
        int i, leap;

        leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
        for (i = 1; yearday > daytab[leap][i]; i++)
            yearday -= daytab[leap][i];
        *pmonth = i;
        *pday = yearday;
    }
    /* month_name:  return name of n-th month */
    char *month_name(int n) {
        static char *name[] = {
            "Illegal month",
            "January", "February", "March",
            "April", "May", "June",
            "July", "August", "September",
            "October", "November", "December"
        };

        return (n < 1 || n > 12) ? name[0] : name[n];
    }

    void testDataConverter() {
        int year=2009,month=6,day=20;
        int dayOfYear=day_of_year(year,month,day);
        std::cout<<dayOfYear<<endl;
        month_day(2010,100,&month,&day);
        std::cout<<month<<" "<<day<<endl;
        //
        //
        int a[1][2][3];

    }

};


#endif // DATACONVERTER_H_INCLUDED
