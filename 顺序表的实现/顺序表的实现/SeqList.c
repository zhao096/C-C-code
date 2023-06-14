 #define _CRT_SECURE_NO_WARNINGS 1

#include"SeqLIst.h"
//sequence 顺序

void If_Add_Capacity(SeqList* obj)
{
	if (obj->size == obj->capacity)//判断已有成员个数是否等于容量,若等则进去
	{
		SLDataType* ptr = (SLDataType*)realloc(obj->a, sizeof(SLDataType) * obj->capacity * 2);//进来后就说明空间不够了，需要开空间
		//一般多直接开辟比容量大两倍的空间 即 对a开辟结构体大小为原capacity两倍的空间
		if (ptr == NULL)
		{
			perror("realloc");

			return;
		}
		obj->a = ptr;//因为可能是异地扩容所以还要将ptr赋值给数组a
		obj->capacity *= 2;//容量 乘于 2
		ptr = NULL;//无用的指针置为NULL（好习惯）
	}
}

void InitSeqList(SeqList* obj)//将结构体用指针接收
{
	assert(obj);

	obj->capacity = INIT_CAPACITY;//通过指针来访问结构体中的成员，将capacity先初始化为INIT_CAPACITY（用宏来确定capacity的起始大小，这样方便后改变）
	obj->size = 0;//0个成员
	obj->a = (SLDataType*)malloc(sizeof(SLDataType) * obj->capacity);//malloc动态申请结构体大小的capacity个空间
	if (obj->a == NULL)//判断一下是否申请成功
	{
		perror("malloc");//如果失败报错
		return;
	}
}

void DestorySeqList(SeqList* obj)//指针接收结构
{
	assert(obj);//判断结构是否为空,防止访问到NULL指针（这是一个好习惯）
	free(obj->a);//直接释放所借用的空间
	obj->a = NULL;//再将其置为NULL
	obj->capacity = obj->size = 0;//将容量和个都置为0,摧毁了自然就没了
}

void SeqListBackPush(SeqList* obj, SLDataType x)//将结构体用指针接收通过指针来找到成员，x是所要尾插的数据
{
	assert(obj);//判断结构体是否为NULL

	If_Add_Capacity(obj);//判断数据是否已经把所借的容量填满了

	obj->a[(obj->size)++] = x;//在a的最后位置插入数据，可以发现其实size个数就是最后位置的下标
}

void SeqListBackPop(SeqList* obj)
{
	assert(obj);//判空
	assert(obj->size > 0);//为真就过、为假就会报错,若没有数据那就是有问题的

	obj->size--;//此处的尾删并不直接将空间归还，而仅仅只是把元素个数-1这样

	//就不会访问到，即使后面需要再次添加数据也就直接覆盖了,因为要归还空间的成本太高了
}




void SeqListFrontPush(SeqList* obj, SLDataType x)
{
	assert(obj);//判空

	If_Add_Capacity(obj);//判是否满了
	for (int i = obj->size; i > 0; i--)//将所有数据往后移一位
	{
		obj->a[i] = obj->a[i - 1];//此处只要是未满的就能直接就行移位并不会有事
	}
	obj->a[0] = x;//在a[0]位置处添加数据
	obj->size++;//元素个数++,这可别忘了！
}

void SeqListFrontPop(SeqList* obj)
{
	assert(obj);//判空
	assert(obj->size > 0);//判断是否有数据
	for (int i = 0; i < obj->size - 1; i++)//直接从第2个位置开始往前覆盖掉即可
	{
		obj->a[i] = obj->a[i + 1];
	}
	obj->size--;//注意要 - - 
}

void SeqListInsert(SeqList* obj, int pos, SLDataType x)//在pos位置处添加数据
{
	assert(obj);//判空
	pos -= 1;//换成下标
	assert(pos >= 0 && pos <= obj->size);//判断这个位置是否有问题
	If_Add_Capacity(obj);//判断是否满了
	int i = obj->size;//和头插的方法几乎一样
	for (i; i > pos; i--)//将从位置处开始的数据全部往后挪一位
	{
		obj->a[i] = obj->a[i - 1];//从尾部开始防止覆盖
	}
	obj->a[i] = x;//在位置处插入数据
	obj->size++;//size++ 别忘了！
}

void SeqListErase(SeqList* obj, int pos)
{
	assert(obj);//判空
	assert(obj->size > 0);//是否有数据

	pos -= 1;//换成下标
	assert(pos >= 0 && pos <= obj->size);//是否符合要求

	for (int i = pos; i < obj->size - 1; i++)//和头删对应此处就应该是从pos+1位置处开始往前覆盖
	{
		obj->a[i] = obj->a[i + 1];//将pos位置处先覆盖 , 然后以此往后
	}
	obj->size--;//注意 - -
}

void SeqListPirnt(SeqList* obj)//指针接收结构体
{
	assert(obj);//判空
	for (int i = 0; i < obj->size; i++)//从下标为0的位置处开始往后遍历
	{
		printf("%d ", obj->a[i]);//结构体访问成员：*obj表示结构体 在 .访问 就还能写成 （*obj）.a[i] 这两个是等价的一般喜欢用前面方法
	}
	printf("\n");//换行
}

