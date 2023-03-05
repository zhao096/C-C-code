#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

 struct ListNode {
  int val;
  struct ListNode *next;
 };

//
//
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    struct ListNode* i1 = list1;
//    struct ListNode* i2 = list2;
//    struct ListNode* i3 = list1->next;
//    struct ListNode* tmp2 = list2->next;
//    while (i3)
//    {
//        if (i1->val < i2->val)
//        {
//            i1->next = i2;
//            i1 = i3;
//            i3 = i3->next;
//        }
//
//        else if (i1->val == i2->val)
//        {
//            i1->next = tmp2;
//            i2->next = i1;
//            i1 = i3;
//            i3 = i3->next;
//        }
//
//        else
//        {
//            if (tmp2->val < i1->val)
//            {
//                i1->next = tmp2->next;
//                tmp2->next = i1;
//                i3 = i3->next;
//                i2 = tmp2;
//            }
//            else {
//
//                i1->next = tmp2;
//                i2->next = i1;
//                i3 = i3->next;
//
//            }
//
//        }
//    }
//
//    return list2;
//}

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


 struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
     struct ListNode* i1 = list1;
     struct ListNode* i2 = list2;
     struct ListNode* i3 = NULL;
     struct ListNode* ret = NULL;
     if (i1 == NULL)
     {
         return i2;//当i1为空返回i2
     }
     if (i2 == NULL) {
         return i1;//同理
     }
     while (i1 && i2)
     {
         //将小的放到i3中
         if (i1->val > i2->val)
         {
             if (i3 == NULL)
             {
                 i3 = i2;
                 ret = i3;
             }
             else {
                 i3->next = i2;
                 i3 = i3->next;
             }
             i2 = i2->next;
         }

         else
         {
             if (i3 == NULL)
             {
                 i3 = i1;
                 ret = i3;

             }
             else {
                 i3->next = i1;
                 i3 = i3->next;
             }
             i1 = i1->next;
         }

     }
     while (i1)
     {

         i3->next = i1;
         i1 = i1->next;
         i3 = i3->next;
     }
     while (i2)
     {
         i3->next = i2;
         i2 = i2->next;
         i3 = i3->next;

     }


     return ret;
 }
int main()
{

    struct ListNode* t1 = (struct ListNode*)malloc(4);
    struct ListNode* t2 = (struct ListNode*)malloc(4);
    struct ListNode* t3 = (struct ListNode*)malloc(4);

    t1->val = 1;
    t2->val = 2;
    t3->val = 4;

    t1->next = t2;
    t2->next = t3;
    t3->next = NULL;
   
    struct ListNode* n1 = (struct ListNode*)malloc(4);
    struct ListNode* n2 = (struct ListNode*)malloc(4);
    struct ListNode* n3 = (struct ListNode*)malloc(4);

    n1->val = 1;
    n2->val = 3;
    n3->val = 4;

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    mergeTwoLists(t1,n1);
}