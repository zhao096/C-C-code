 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	//一维数组
	//int a[] = { 1,2,3,4 };
	//printf("%d\n", sizeof(a));
	//printf("%d\n", sizeof(a + 0));
	//printf("%d\n", sizeof(*a));
	//printf("%d\n", sizeof(a + 1));
	//printf("%d\n", sizeof(a[1]));
	//printf("%d\n", sizeof(&a));
	//printf("%d\n", sizeof(*&a));
	//printf("%d\n", sizeof(&a + 1));
	//printf("%d\n", sizeof(&a[0]));
	//printf("%d\n", sizeof(&a[0] + 1));
	
	////
	//////字符数组
	////char arr[] = { 'a','b','c','d','e','f' };
	////printf("%d\n", sizeof(arr));
	////sizeof只看类型：sizeof(char [6]) --> 1 * 6 = 6 byte
	////printf("%d\n", sizeof(arr + 0));
	////数组名+1 -> 首元素地址+1 -》第二个元素的地址  -》 4/8
	////printf("%d\n", sizeof(*arr));
	////对首元素地址解应用得到首元素其类型是char -》 sizeof(char) --》 1byte
	////printf("%d\n", sizeof(arr[1]));
	////同理得到下标为1的元素 -》 其类型是 char -》 1byte
	////printf("%d\n", sizeof(&arr));
	////取到整个数组的地址，是地址大小为 4/8
	////printf("%d\n", sizeof(&arr + 1));
	////地址+1 仍是地址 -》 4/8
	////printf("%d\n", sizeof(&arr[0] + 1));
	////取到首元素的地址 再 + 1 就是第二个元素的地址 -》 4/8
	////
	////printf("%d\n", strlen(arr));
	////因为arr内没有\0所以并不会停止，所以最终将产生一个 随机值
	////printf("%d\n", strlen(arr + 0));
	//////同上arr + 0 首元素地址 + 0 仍然为首元素地址
	////
	////printf("%d\n", strlen(*arr));
	//////对首元素地址解应用得到首元素，但是strlen需要传进去一个地址，所以将会报错因为将
	//////'a'的ASCII码值传进去系统认为你要访问地址为97的地址，这非法访问了 最终将会报错
	////
	////printf("%d\n", strlen(arr[1]));
	//// 
	////同理此处将要非法访问 'b'-> 98 处的地址 会报错
	////
	////printf("%d\n", strlen(&arr));
	////传进去整个数组的地址，同样无法找到\0而自动停止所以一样是随机值
	////printf("%d\n", strlen(&arr + 1));
	////+1也是同理找不到\0
	////printf("%d\n", strlen(&arr[0] + 1));
	////首元素地址+1 第二个元素的地址，同样的找不到

	/*数组存字符串*/
	//char arr[] = "abcdef";
	//printf("%d\n", sizeof(arr));
	////整个数组的大小为1 * 7 = 7byte
	//printf("%d\n", sizeof(arr + 0));
	////首元素地址+1  最终大小为指针的大小为 4/8
	//printf("%d\n", sizeof(*arr));
	////找到首元素，首元素的类型为char 所以大小为 1byte
	//printf("%d\n", sizeof(arr[1]));
	////同理找到下标为1的元素 大小为 1byte
	//printf("%d\n", sizeof(&arr));
	////取出整个数组的地址 ， 但是仍然是地址 所以大小为 4/8
	//printf("%d\n", sizeof(&arr + 1));
	////同理+1跳过整个数组 ，但是还是指针 所以大小为4 / 8 
	//printf("%d\n", sizeof(&arr[0] + 1));
	//// 对第一个元素的地址+1 指向第二个元素的地址还是地址 所以大小为 4/8

	//printf("%d\n", strlen(arr));
	////arr表示首元素的地址（没放在sizeof内） 因为字符串最后会自动放一个\0所以最终求出的长度为 6
	//printf("%d\n", strlen(arr + 0));
	////arr + 0 == arr 所以和第一个一样  长度为 6
	////printf("%d\n", strlen(*arr));
	//////取到第一个元素 ‘a’传进去的是其ASCII码 97 这样就会非法访问地址97 使之报错 
	////printf("%d\n", strlen(arr[1]));
	////同上取到‘b’
	//printf("%d\n", strlen(&arr));
	////取到整个数组的地址，其实和首元素地址一样，但值得注意的是strlen内部的参数是const char * 所以只会一个个字符的跳过 最终长度也为6 
	//printf("%d\n", strlen(&arr + 1));
	////因为其是整个数组的地址+1跳过了这个数组 而数组后面的\0是不确定的所以是个随机值
	//printf("%d\n", strlen(&arr[0] + 1));
	////首元素地址 + 1 指向第二个元素的地址 从第二个元素开始的话到\0就会有5元素
	
	////指针存常量字符串
	//char* p = "abcdef";
	//printf("%d\n", sizeof(p));
	////指针变量存的是常量字符串的首元素的地址，所以 大小为4/8
	//printf("%d\n", sizeof(p + 1));
	////同理指针+1指向下一个元素的地址，所以 还是 4/8
	//printf("%d\n", sizeof(*p));
	////*p找到首元素a 其类型为char 所以最终的 大小为 1
	//printf("%d\n", sizeof(p[0]));
	////和*p 相同都是找到首元素 ，所以大小也为 1
	//printf("%d\n", sizeof(&p));
	////取出p的地址（类似char **）但是不管怎样还是地址 所以大小为4/8
	//printf("%d\n", sizeof(&p + 1));
	////同理 地址 + 1 还是 地址  是地址大小就是 4/8
	//printf("%d\n", sizeof(&p[0] + 1));
	////同理首元素的地址 + 1 还是地址 大小：4/8


	//printf("%d\n", strlen(p));
	////将p传进p存的是a的地址 所以从a开始往后找\0之前的元素最终找到6个元素
	//printf("%d\n", strlen(p + 1));
	////同理从第二个元素的地址开始 剪掉第一个元素 就为5
	//
	////printf("%d\n", strlen(*p));
	//////*p找到元素'a'和之前的题一样会报错
	////printf("%d\n", strlen(p[0]));
	//////同上...
	//printf("%d\n", strlen(&p));
	////&p 取到的是变量p的地址而该地址存在了另一个空间，所以后面的\0位置是未知的所以仍然会产生随机值
	//printf("%d\n", strlen(&p + 1));
	////&p+1 同理取到的是存变量p的地址在+1最终后面的\0位置同样未知
	//printf("%d\n", strlen(&p[0] + 1));
	////& p[0] 其p[0] == *p 再加回 & -> &*p 再抵消 p 再+1 就得到了 常量字符串的第二个元素的地址 'b' 再向后面找\0 得到5byte

	//二维数组
	//	此处改成x64
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));
	//sizeof内只有数组名是表示整个数组的大小 即 12 * 4 = 48
	printf("%d\n", sizeof(a[0][0]));
	//找到第一行第一列元素 其类型是 int 4byte
	printf("%d\n", sizeof(a[0]));
	//a【0】表示第一行的数组名而又单独放在了sizeof内部所以直接算出整个第一行数组的大小16
	printf("%d\n", sizeof(a[0] + 1));
	//次数没有单独放在sizeof内所以表示第一行首元素地址 + 1 找到第一行第二个元素的地址所以大小就是 4/8
	printf("%d\n", sizeof(*(a[0] + 1)));
	//找到第一行第二个元素 其类型是int所以大小为 4byte
	printf("%d\n", sizeof(a + 1));
	//此时没有单独放在sizeof内所以表示整个第一行的地址 + 1 指向第二行 ，是地址所以大小为 4/8
	printf("%d\n", sizeof(*(a + 1)));
	//取出整个第二行所以大小 为 4（4个元素） * 4(int) = 16
	printf("%d\n", sizeof(&a[0] + 1));
	//取到整个第一行的地址 再+ 1 表示第二行的地址 所以大小为 4 /8
	printf("%d\n", sizeof(*(&a[0] + 1)));
	//取到第二行的地址后在解引用找到整个第二行 所以大小就是 16
	printf("%d\n", sizeof(*a));
	//a表示第一行的地址解引用就表示这个第一行 所以大小就是 4 * 4 = 16
	printf("%d\n", sizeof(a[3]));
	//注意此处虽然越界了 当是记住sizeof 只看类型并不关注内部 又因为第三行的数组名直接放在sizeof内 所以最终大小为16
	

	return 0;
}