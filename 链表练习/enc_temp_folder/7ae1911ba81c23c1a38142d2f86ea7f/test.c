 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
//typedef struct ListNode {
//    int val;
//    struct ListNode *next;
//}ListNode;
//
//
//
//
//    ListNode* reversion(ListNode* head)
//    {
//        if (head == NULL)
//        {
//            return head;
//        }
//        struct ListNode* cur = head, * tail = NULL, * prev = head->next;
//        while (cur)
//        {
//            cur->next = tail;
//            tail = cur;
//            cur = prev;
//
//            if (prev)
//            {
//                prev = prev->next;
//
//            }
//        }
//        return tail;
//
//    }
//    ListNode* middleNode(ListNode* head) {
//        ListNode* fast, * slow;
//        fast = slow = head;
//        while (fast && fast->next)
//        {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        return slow;
//    }
//
//
//    bool chkPalindrome(ListNode* head) {
//        ListNode* mid = middleNode(head);
//        ListNode* rhead = reversion(mid);
//        while (rhead)
//        {
//            if (rhead->val != head->val)
//            {
//                return false;
//            }
//            rhead = rhead->next;
//            head = head->next;
//        }
//        return true;
//
//    }




struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* listA, * listB;
    listA = headA;
    listB = headB;
    int count1 = 1, count2 = 1;
    while (listA->next)
    {
        count1++;
        listA = listA->next;
    }
    while (listB->next)
    {
        count2++;
        listB = listB->next;
    }
    if (listB != listA)
    {
        return NULL;
    }
    int max = abs(count1 - count2);
    listA = headA;
    listB = headB;
    if (count1 < count2)
    {
        listA = listB;
        listB = headA;

    }
    while (max--)
    {
        listA = listA->next;
    }

    while (listA->next != listB->next)
    {
        listB = listB->next;
        listA = listA->next;
    }

    return listA->next;
}

int main()
{
    struct ListNode* s1 = (struct ListNode*)malloc(sizeof(struct ListNode));

    s1->val = 1;

    s1->next = NULL;
    
    
    getIntersectionNode(s1, s1);

    return 0;
}