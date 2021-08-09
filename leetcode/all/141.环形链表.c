/*
 * @lc app=leetcode.cn id=141 lang=c
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (!head)
        return false;

    struct ListNode *p, *q;

    p = head;
    q = head->next;

    while (p && q && (q->next))
    {
        p = p->next;
        q = q->next->next;

        if (p == q)
            return true;
    }

    return false;
}
// @lc code=end

