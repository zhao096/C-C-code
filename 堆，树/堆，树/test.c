
#define _CRT_SECURE_NO_WARNINGS 1

void Adjustup(HPDataType* a, int child)
{
	int parent = (chile - 1) / 2;
	while (parent>= 0)/////////////
	{
		if (a[parent] < a[chile])
		{
			int tmp = a[parent];
			a[parnet] = a[achild];
			a[child] = tmp;
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}