 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//ÈçÐÇÆÚ
enum Day
{
    Mon,
    Tues=10,
    Wed,
    Thur,
    Fri,
    Sat,
    Sun
};

int main()
{
    //printf("%d", Mon);
    printf("%d", sizeof(enum Day));
	return 0;
}