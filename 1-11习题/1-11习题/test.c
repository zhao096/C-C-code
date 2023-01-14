 #define _CRT_SECURE_NO_WARNINGS 1
//#define MAX_SIZE 2+3
//
//int main()
//{
//	struct _Record_Struct
//	{
//		unsigned char Env_Alarm_ID : 4;
//		unsigned char Para1 : 2;
//		unsigned char state;
//		unsigned char avail : 1;
//	}*Env_Alarm_Record;
//	struct _Record_Struct* pointer = (struct _Record_Struct*)malloc(sizeof(struct _Record_Struct) * MAX_SIZE);
//	return 0;
//}
#include<stdio.h>
#include<string.h>
int main()
{
    unsigned char puc[4];
    struct tagPIM
    {
        unsigned char ucPim1;
        unsigned char ucData0 : 1;
        unsigned char ucData1 : 2;
        unsigned char ucData2 : 3;
    }*pstPimData;
    pstPimData = (struct tagPIM*)puc;
    memset(puc, 0, 4);
    pstPimData->ucPim1 = 2;
    pstPimData->ucData0 = 3;
    pstPimData->ucData1 = 4;
    pstPimData->ucData2 = 5;
    printf("%d %d %d %d\n", puc[0], puc[1], puc[2], puc[3]);
    return 0;
}