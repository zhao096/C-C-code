 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;   
    struct ListNode *next;
};
 


struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
        struct ListNode* curr = NULL;
        struct ListNode* prev = head;
        struct ListNode* tmp = head;
        while (tmp)
        {
            tmp = prev->next;//怎么才能防止prev-》next的地址被改变后找不到
            prev->next = curr;
            curr = prev;
            if(tmp)
            prev = tmp;
        }
    return prev; 
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

    reverseList(t1);
}