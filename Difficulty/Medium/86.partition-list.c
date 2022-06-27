/*
 * @lc app=leetcode id=86 lang=c
 *
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (48.13%)
 * Likes:    3563
 * Dislikes: 495
 * Total Accepted:    347.6K
 * Total Submissions: 720.3K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given the head of a linked list and a value x, partition it such that all
 * nodes less than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,4,3,2,5,2], x = 3
 * Output: [1,2,2,4,3,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [2,1], x = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [0, 200].
 * -100 <= Node.val <= 100
 * -200 <= x <= 200
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


struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *small,*current;
    struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->next = head;
    small = current = head = temp;
    while(current->next != NULL){
        if(current->next->val < x){
            if(current == small){
                small = current = current->next;
            }
            else{
                temp = current->next;
                current->next = temp->next;
                temp->next = small->next;
                small->next = temp;
                small = temp;
            }
        }
        else{
            current = current->next;
        }
    }
    return head->next;
}
// @lc code=end
// @lc MEDIUM