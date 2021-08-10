/*
 * @lc app=leetcode.cn id=206 lang=c
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;

    while (curr)
    {
        struct ListNode *next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
// @lc code=end

