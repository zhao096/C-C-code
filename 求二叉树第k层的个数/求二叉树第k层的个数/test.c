 #define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct BinaryTreeNode
{
	int val;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}Node;


int TreeLevel(Node* root,int k)//从根开始的k层的元素个数 = 从根开始的左子树 k - 1层的个数 + 从根开始的右子树 k - 1层的个数
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)//左子树 k - 1层的个数 + 从根开始的右子树 k - 1层的个数 只有当k到达所要求的层数时才会进行返回1
	{
		return 1;
	}
	return TreeLevel(root->left, k-1)+ TreeLevel(root->right, k-1) ;//此处不能用-- 因为当前面的--了就会导致在那个栈帧内的k减1了
}

Node*  BuyNode(int x)
{
	Node* root = (Node*)malloc(sizeof(Node));
	if(root == NULL)
	{
		perror("malloc");
		return NULL;
	}
	root->val = x;
	root->left = NULL;
	root->right = NULL;
	return root;
}
int main()
{
	Node* t1 = BuyNode(1);
	Node* t2 = BuyNode(2);
	Node* t3 = BuyNode(4);
	Node* t4 = BuyNode(3);
	Node* t5 = BuyNode(5);
	Node* t6 = BuyNode(6);
	Node* t7 = BuyNode(7);

	t1->left = t2;
	t1->right = t3;

	t2->left = t6;
	t6->right = t7;

	t3->left = t4;
	t3->right = t5;

	int k = 0;
	printf("请输入要求的从根开始的第几层的个数:");
	scanf("%d", &k);
	int ret = TreeLevel(t1,k);
	printf("%d", ret);

	free(t1);
	free(t2);
	free(t3);
	free(t4);
	free(t5);
	free(t6);
	free(t7);
	return 0;
}

