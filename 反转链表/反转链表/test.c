 #define _CRT_SECURE_NO_WARNINGS 1

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)//对只有一个元素时的情况单独处理
        return head;
    struct ListNode* cur = head, * tail = head->next, * prev = NULL;
    while (cur)
    {
        //思路把数据的链表链接反过来，三指针
        cur->next = prev;//把cur指向prev（prev是前一个位置的空间、当没有前面位置时为NULL也反向代表最后一个位置）
        prev = cur;//把prev指向改变成已经改变链接的节点
        cur = tail;//把cur指向记录好的后面位置
        if (tail)
            tail = tail->next;
    }
    return prev;

}