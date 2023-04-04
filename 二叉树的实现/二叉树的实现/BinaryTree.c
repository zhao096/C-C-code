 #define _CRT_SECURE_NO_WARNINGS 1

#include"BinaryTree.h"
#include"Queue.h"

//通过前序遍历用数组a内的数据创造一个二叉树
//递归思想
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	assert(a && pi);//一假则假
	if (a[*pi] == '#')
	{
		(*pi)++;//记住此处也要++，因为此时是拿数组再走的，如果不加遇到#就不会往前走一直在#
		return NULL;
	}

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL)
	{
		perror("malloc");
		exit(0);
	}

	//前序遍历的思想
	root->_data = a[(*pi)++];//直接通过++ 即可将整个数组进行遍历
	root->_left = BinaryTreeCreate(a , n, pi);
	root->_right = BinaryTreeCreate(a, n, pi);

	return root;
}


void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)//遇到空不用销毁
	{
		return;
	}
	//利用后序思想来销毁，如果有前序后者中序会导致非法访问已释放的空间
	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	free(root);

}


//中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return BinaryTreeSize(root->_left)
		+  BinaryTreeSize(root->_right) + 1;

}
//求子叶节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int t1 = BinaryTreeLeafSize(root->_left);
	int t2 = BinaryTreeLeafSize(root->_right);
	if (!( t1+t2 ))
	{
		return 1;
	}
	return t1+ t2;
}


int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}

	return 	BinaryTreeLevelKSize(root->_left, k-1)
	+ BinaryTreeLevelKSize(root->_right, k-1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	
	BTNode* t1 = BinaryTreeFind(root->_left,x);
	if (t1)
		return t1;
	
	BTNode* t2 = BinaryTreeFind(root->_right,x);
	if(t2)
		return t2;
	
	return NULL;
}


void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}


void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%c ", root->_data);

}

// 层序遍历
//通过队列的先进先出让，堆顶先进然后出的时候打印并且带入左右子树

// 先将最大的放进
void BinaryTreeLevelOrder(BTNode* root) {
	Queue q;
	QueueInit(&q);
	//进第一个元素
	QueuePush(&q, root);

	while (root = QueueFront(&q))//改变root,让其从队列的头来获取
	{	

		//出并且打印
		QDataType ret = QueueFront(&q);
		if(ret)
		printf("%c", ret->_data);
		QueuePop(&q);

		//出后将其左右带进
		QueuePush(&q, root->_left);
		QueuePush(&q, root->_right);

	}
}


// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	//将所有数据数据遍历完，如果在最后的有NULL和数据交叉就说明这不是一个完全二叉树
	//即如 左树为NULL 右树为数据
	Queue q;
	QueueInit(&q);
	//放进第一个元素
	QueuePush(&q, root);
	while (root = QueueFront(&q))
	{
		//出并且打印
		QDataType ret = QueueFront(&q);
		QueuePop(&q);

		//出后将其左右带进
		QueuePush(&q, root->_left);
		QueuePush(&q, root->_right);

	}

	//此时已经将数据遍历完了遇到了一个NULL
	while (!QueueEmpty(&q))
	{
		if (QueueFront(&q))
			return false;
		QueuePop(&q);
	}
	return true;
}
