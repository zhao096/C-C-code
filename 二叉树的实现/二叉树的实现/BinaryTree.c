 #define _CRT_SECURE_NO_WARNINGS 1

#include"BinaryTree.h"
//通过前序遍历用数组a内的数据创造一个二叉树
//递归思想
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] == '#')
	{
		return NULL;
	}

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL)
	{
		perror("node");
		exit(0);
	}

	root->_data = a[(*pi)++];//直接通过++ 即可将整个数组进行遍历
	root->_left = BinaryTreeCreate(a , n, pi);
	root->_right = BinaryTreeCreate(a, n, pi);
	return root;
}
