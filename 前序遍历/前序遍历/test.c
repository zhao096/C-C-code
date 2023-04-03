#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */

int Binarynumber(struct TreeNode* root)
{
	if (root == NULL) {
		return 0;
	}
	return Binarynumber(root->right) + Binarynumber(root->left) + 1;
}

void Traversal(struct TreeNode* root, int* ret, int* i)
{
	if (root == NULL)
	{
		return;
	}
	ret[*i] = root->val;
	*i += 1;
	Traversal(root->left, ret, i);
	Traversal(root->right, ret, i);
}





int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = Binarynumber(root);
	int* ret = (int*)malloc(sizeof(int) * (*returnSize));
	if (root == NULL)
	{
		return NULL;
	}
	int i = 0;
	Traversal(root, ret, &i);

	return ret;
}

struct TreeNode* BuyNode(int x)
{
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = x;
	root->left = NULL;
	root->right = NULL;
	return root;
}
int main()
{
	struct TreeNode* t1 = BuyNode(3);
	struct TreeNode* t2 = BuyNode(1);
	struct TreeNode* t3 = BuyNode(2);
	struct TreeNode* t4 = BuyNode(3);
	struct TreeNode* t5 = BuyNode(5);
	struct TreeNode* t6 = BuyNode(6);
	struct TreeNode* t7 = BuyNode(7);

	t1->left = t2;
	t1->right = t3;
	int arr[100] = { 0 };
	preorderTraversal(t1, arr);

	return 0;
}