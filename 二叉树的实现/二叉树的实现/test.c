 #define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"

int main()
{
	char a[18] = "ABDH###E##CF##G##";

	int pi = 0;
	BTNode*  root = BinaryTreeCreate(a, strlen(a), &pi);


	BinaryTreeInOrder(root);

	int number1 = BinaryTreeSize(root);
	printf("%d\n", number1);


	int number2 = BinaryTreeLeafSize(root);
	printf("%d\n", number2);


	int number3 = BinaryTreeLevelKSize(root,4);
	printf("%d\n", number3);


	BTNode* node = BinaryTreeFind(root, 'A');
	if(node)
	printf("%c\n", node->_data);

	BinaryTreeLevelOrder(root);
	printf("\n");

	bool ret = BinaryTreeComplete(root);
	printf("%d", ret);

	BinaryTreeDestory(root);
	root = NULL;

	return 0;
}