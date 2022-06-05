/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    /* border limitation */
    if (!l1) {return l2;}
    if (!l2) {return l1;}

    struct ListNode* p1 = l1;
    struct ListNode* p2 = l2;
    struct ListNode* ans = (struct ListNodes*)malloc(sizeof(struct ListNode));
    struct ListNode* freep = 0;
    int c = 0;
    ans->val = 0;

    while (p1 != 0 || p2 != 0 || c != 0)
    {
        if (freep == 0) {freep = ans;}
        else {
            freep->next = (struct ListNodes*)malloc(sizeof(struct ListNode));
            freep->next->val = 0;
            freep = freep->next;
        }
        int s = ((p1 != 0 ? p1->val : 0) + (p2 != 0 ? p2->val : 0) + c);
        c = s/10;
        freep->val = s%10;
        freep->next = 0; /* Make sure the Last of the LinkNode end with a NULL ->next */
        p1 = p1 == 0 ? 0 : p1->next;
		p2 = p2 == 0 ? 0 : p2->next;
    }
    return ans;
}
// @lc code=end
// @lc MEDIUM