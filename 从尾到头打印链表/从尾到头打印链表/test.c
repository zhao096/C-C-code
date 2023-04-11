 #define _CRT_SECURE_NO_WARNINGS 1
#include"STist.h"


 struct ListNode {
      int val;
      struct ListNode *next;
 };

 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */

void ReserveArr(int* a, int n)
{
    int left = 0, right = n - 1;;
    while (left < right)
    {
        int tmp = a[left];
        a[left++] = a[right];
        a[right--] = tmp;
    }
}

int* reversePrint(struct ListNode* head, int* returnSize) {
    int *a = (int *) malloc(sizeof(int) * 10000);
    int number = 0;
    while (head != NULL)
    {
        a[number++] = head->val;
        head = head->next;
    }

    ReserveArr(a, number);

    *returnSize = number;

    return a;
}
int main()
{

    SListPushBack()


	return 0;
}