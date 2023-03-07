 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* FindKthToTail(struct ListNode* pListHead, unsigned int k) {
    struct ListNode* slow = pListHead;
    struct ListNode* fast = slow;
    while (k--)
    {
        if (fast)
            fast = fast->next;
        else
            return NULL;
    }

    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
int main()
{
    struct ListNode* head = NULL;

    struct ListNode* t1 = (struct ListNode*)malloc(4);
    struct ListNode* t2 = (struct ListNode*)malloc(4);
    struct ListNode* t3 = (struct ListNode*)malloc(4);

    t1->val = 1;
    t2->val = 2;
    t3->val = 3;

    t1->next = t2;
    t2->next = t3;
    t3->next = NULL;

    FindKthToTail(t1,1);
}