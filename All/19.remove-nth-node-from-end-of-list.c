/*
 * @lc app=leetcode id=19 lang=c
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (38.49%)
 * Likes:    10488
 * Dislikes: 494
 * Total Accepted:    1.4M
 * Total Submissions: 3.8M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, remove the n^th node from the end of the
 * list and return its head.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1], n = 1
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1,2], n = 1
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 * 
 * 
 * 
 * Follow up: Could you do this in one pass?
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int LinkLen(struct ListNode* L) {
    if (L == NULL) {return 0;}
    int l = 0;
    while (L != NULL)
    {
        ++l; L = L->next;
    }
    return l;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p, *dummy;
    p = head; dummy = p;
    
    int len = LinkLen(p);
    if (len == 1) {return NULL;}
    int skip_idx = len + 1 -n;
    printf("length of the linked list is %d, Skip idx is %d\n", len, skip_idx);

    int idx = 1;
    while (p != NULL)
    {
        ++idx;
        if (idx != skip_idx) {
            p = p->next;
        } else {
            p->next = p->next->next;
            ++idx;
        }
    }
    return (skip_idx == 1)? dummy->next : dummy;
}
// @lc code=end
// @lc MEDIUM