 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//    FILE* pf = fopen("test.txt", "w");//同过写的方式来打开文件，在每次写的时候都相当于重新创建一个文件，将原文件数据覆盖
//    if (pf == NULL)//防止开辟失败，访问NULL
//    {
//        perror("fopen");
//        return 1;
//    }
//
//    //使用文件 此处省略
//    for (int i = 'a'; i <= 'z';i++)
//    {
//        fputc(i, pf);
//    }
//
//    //关闭文件
//    fclose(pf);
//    pf = NULL;
//
//    FILE* pf1 = fopen("test.txt", "r");//同过写的方式来打开文件，在每次写的时候都相当于重新创建一个文件，将原文件数据覆盖
//    if (pf1== NULL)//防止开辟失败，访问NULL
//    {
//        perror("fopen");
//        return 1;
//    }
//
//    //使用文件 此处省略
//    for (int i = 'a'; i <= 'z'; i++)
//    {
//        int ch = fgetc(pf1);
//        printf("%c ", ch);
//    }
//
//    //关闭文件
//    fclose(pf1);
//    pf1 = NULL;
//     
//    return 0;
//}




//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fputs("hello world\n", pf);//文件输出函数
//	fputs("hello bit\n", pf);
//
//	fclose(pf);
//	pf = NULL;
//
//
//	FILE* pf1 = fopen("test.txt", "r");
//	if (pf1 == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	char ch[20] = { 0 };
//	fgets(ch, 12, pf1);//文件输入函数再读取输出，并且此时字符串时12个字符那么就需要13个空间，因为fgets会在最后加上一个\0(所以此处只会那取 12 - 1 个字符 在最后12的位置要放上\0 )
//	printf("%s", ch);//hello world
//
//
//
//	fgets(ch, 10, pf1);
//	//此处因为一开始将前面的11（num - 1）个字符读去了在第一行还剩下一个\n所以就会把\n读取到，并且fgets遇到\n会自动停止并且将\n换成\0，并且因为只读一行所以会直接返回
//	printf("%s", ch);//打印\n
//
//	fgets(ch, 11, pf1);//来到下一行，此时字符串有10个空间,第11的位置放\0
//	printf("%s", ch);//打印hello bit\n
//
//	fclose(pf1); 
//	pf1 = NULL;
//	return 0;
//}


//struct S
//{
//	int a;
//	char arr[20];
//	float c;
//};
//
//int main()
//{
//	struct S s = { 100,"李四",120.00 };
//	FILE* pf = fopen("test.txt","w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fprintf(pf,"%d %s %f",s.a,s.arr,s.c);
//
//	fclose(pf);
//	pf = NULL;
//
//	FILE* pf1 = fopen("test.txt","r");
//	if (pf1 == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fscanf(pf1,"%d %s %f",&(s.a),s.arr,&(s.c));
//	printf("%d %s %f\n", s.a, s.arr, s.c);
//
//	fclose(pf1);
//	pf1 = NULL;
//
//	return 0;
//}
//struct S
//{
//	int a;
//	char arr[20];
//	float c;
//};
//
//int main()
//{
//
//	struct S s = { 0 };
//	//int ch = fgetc(stdin);
//	//fputc(ch,stdout);
//	fscanf(stdin, "%d %s %f", &(s.a), s.arr, &(s.c));
//	fprintf(stdout, "%d %s %f", s.a, s.arr, s.c);
//
//
//
//	return 0;
//}
//
//struct S
//{
//	int a;
//	char arr[20];
//	float c;
//};

//int main()
//{
//	struct S s = { 123,"李四",321 };
//	FILE* pf = fopen("test.txt", "wb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fwrite(&s, sizeof(struct S), 1, pf);
//
//	fclose(pf);
//	pf = NULL;
//
//	struct S s1 = {0};
//	FILE* pf1 = fopen("test.txt", "rb");
//	if (pf1 == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fread(&s1, sizeof(struct S), 1, pf1);
//	printf("%d %s %f", s1.a, s1.arr, s1.c);
//
//	fclose(pf1);
//	pf1 = NULL;
//
//	return 0;
//}


	//int main()
	//{
	//	struct S s = { 123,"李四",321.0 };
	//	char tmp[100] = { 0 };
	//	sprintf(tmp , "%d %s %f",s.a,s.arr,s.c);//将结构体s的数据输出tmp内
	//	printf("%s\n", tmp);

	//	struct S s1 = { 0 };

	//	sscanf(tmp, "%d %s %f", &(s1.a), s1.arr, &(s1.c));//将tmp得到的数据输入到结构体s1内
	//	printf("%d %s %f", s1.a, s1.arr, s1.c);

	//	return 0;
	//}


int main()
{
	FILE* pf = fopen("test.txt", "r");
	if (NULL == pf)
	{
		perror("fopen");
		return 0;
	}
	int ch = fgetc(pf);
	printf("%c\n", ch);//a
	

	ch = fgetc(pf);
	printf("%c\n", ch);//b


	ch = fgetc(pf);
	printf("%c\n", ch);//c

	//此时因为fgetc返回后会自动往后走一步
	//所以若想重新打印a
	//则可以通过fseek函数来实现,此时指向d应该往后偏移3步
	fseek(pf, -2, SEEK_CUR);

	ch = fgetc(pf);
	printf("%c\n", ch);//b

	printf("%d\n", ftell(pf));//2

	rewind(pf);
	ch = fgetc(pf);
	printf("%c\n", ch);//a
	return 0;
}