/*
 * @lc app=leetcode id=23 lang=c
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (47.30%)
 * Likes:    12555
 * Dislikes: 483
 * Total Accepted:    1.3M
 * Total Submissions: 2.7M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * You are given an array of k linked-lists lists, each linked-list is sorted
 * in ascending order.
 * 
 * Merge all the linked-lists into one sorted linked-list and return it.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: lists = [[1,4,5],[1,3,4],[2,6]]
 * Output: [1,1,2,3,4,4,5,6]
 * Explanation: The linked-lists are:
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * merging them into one sorted list:
 * 1->1->2->3->4->4->5->6
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: lists = []
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: lists = [[]]
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] is sorted in ascending order.
 * The sum of lists[i].length will not exceed 10^4.
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
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

/* O(3NlogN) */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if (listsSize == 0) {return NULL;}

    struct ListNode *p = malloc(sizeof(struct ListNode));
    struct ListNode *res = p;
    struct ListNode *q;

    int size = 0;
    for (int i = 0; i < listsSize; ++i) {
        q = malloc(sizeof(struct ListNode)); q->next=NULL;
        q = lists[i];
        while (q != NULL) {
            q = q->next; ++size;
        }
    }
    if (size == 0) {return NULL;}
    printf("size is %d\n", size);
    int *sort = (int*)malloc(sizeof(int) * size);
    int sort_i = 0;
    for (int i = 0; i < listsSize; ++i) {
        while (lists[i] != NULL) {
            sort[sort_i] = lists[i]->val;
            lists[i] = lists[i]->next;
            ++sort_i;
        }
    }
    qsort(sort, size, sizeof(int), cmp);
    for (int i = 0; i < size; ++i) {
        q = malloc(sizeof(struct ListNode)); q->next=NULL;
        q->val = sort[i];
        p->next = q;
        p = p->next;
    }
    return res->next;
}
// @lc code=end
// @lc MEDIUM