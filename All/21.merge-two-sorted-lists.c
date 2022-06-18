/*
 * @lc app=leetcode id=21 lang=c
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (60.56%)
 * Likes:    12732
 * Dislikes: 1160
 * Total Accepted:    2.3M
 * Total Submissions: 3.8M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * You are given the heads of two sorted linked lists list1 and list2.
 * 
 * Merge the two lists in a one sorted list. The list should be made by
 * splicing together the nodes of the first two lists.
 * 
 * Return the head of the merged linked list.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: list1 = [1,2,4], list2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: list1 = [], list2 = []
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: list1 = [], list2 = [0]
 * Output: [0]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in both lists is in the range [0, 50].
 * -100 <= Node.val <= 100
 * Both list1 and list2 are sorted in non-decreasing order.
 * 
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
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode dummy;
    struct ListNode *p = &dummy;
    
    if (!list1 && !list2) {return NULL;}

    while (list1 && list2)
    {
        if (list1->val < list2->val) {
            p->next = list1;
            list1 = list1->next;
            p = p->next;
        }
        else {
            p->next = list2;
            list2 = list2->next;
            p = p->next;
        }
    }

    if (list1) {p->next = list1;}
    if (list2) {p->next = list2;}
    
    return  dummy.next;
}
// @lc code=end

