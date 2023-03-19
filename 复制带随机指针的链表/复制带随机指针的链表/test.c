 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

// struct Node* CompareNode(struct Node* cur, struct Node* tail_new,struct Node* head)
// {
//     struct Node* list_old = head;
//     struct Node* list_new = tail_new;

//     while (list_old)
//     {
//         if (cur->random == list_old)
//         {
//             return list_new;
//         }
//         list_old = list_old->next;
//         list_new = list_new->next;
//     }
//     return NULL;

// }

// struct Node* BuyMemory(struct Node* tail_old)
// {
//     struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
//     if (ptr == NULL)
//     {
//         perror("malloc::BuyMemory");
//         return NULL;
//     }
//     ptr->val = tail_old->val;
//     ptr->next = tail_old->next;
//     ptr->random = tail_old->random;
//     return ptr;
// }


// struct Node* copyRandomList(struct Node* head) {
//     if (head == NULL)
//     {
//         return NULL;
//     }
//     struct Node* tail_old = head;

//     struct Node* tail_new = NULL;

//     struct Node*newList = tail_new;
//     while (tail_old)
//     {
//         if (tail_new == NULL)
//         {
//             tail_new = BuyMemory(tail_old);
//             newList = tail_new;
//         }
//         else
//         {
//             newList->next = BuyMemory(tail_old);
//             newList = newList->next;
//         }
//         tail_old = tail_old->next;
//     }

//     struct Node* cur = tail_new;
//     while (cur)
//     {
//         struct Node* ret = CompareNode(cur,tail_new, head);

//         cur->random = ret;

//         cur = cur->next;
//     }
//     return tail_new;

// }
struct Node* copyRandomList(struct Node* head) {
    struct Node* cur = head;
    struct Node* copy = NULL;

    while (cur)
    {
        copy = (struct Node*)malloc(sizeof(struct Node));
        struct Node* next = cur->next;

        copy->next = next;
        cur->next = copy;

        copy->val = cur->val;
        copy->random = cur->random;
            
        cur = copy->next;
    }
    cur = head;
    while (cur)
    {
        if (cur->next->random != NULL)
        {
            cur->next->random = cur->random->next;
        }
        else {
            cur->next->random = NULL;
        }
        cur = cur->next->next;
    }
    cur = head;

    struct Node* copyhead = NULL, *copytail = NULL;
    while (cur)
    {
        struct Node* next = cur->next->next;

        if (copyhead == NULL)
        {
            copytail = copyhead = cur->next;
        }
        else {
            copytail->next = cur->next;
            copytail = copytail->next;

        }
        cur = next;
    }
    free()
    return copyhead;
}


int main()
{
    struct Node* s1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* s2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* s3 = (struct Node*)malloc(sizeof(struct Node));


    s1->val = 1;
    s2->val = 2;

    s1->random = s2;
    s2->random = s2;

    s1->next = s2;
    s2->next = NULL;


    struct Node*  ret  = copyRandomList(s1);

    free(ret);
    ret = NULL;


    return 0;
}