/*
 * @lc app=leetcode id=145 lang=c
 *
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (64.52%)
 * Likes:    4382
 * Dislikes: 142
 * Total Accepted:    749.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the postorder traversal of its
 * nodes' values.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,null,2,3]
 * Output: [3,2,1]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = []
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1]
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of the nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 * 
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void PostOrder(struct TreeNode* root, int* res, int* i) {
    if (root == NULL) {return;}
    PostOrder(root->left, res, i);
    PostOrder(root->right, res, i);
    res[(*i)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int *res = malloc(sizeof(int)*100); memset(res, 0, sizeof(int));
    PostOrder(root, res, returnSize);
    return res;
}
// @lc code=end
// @lc EASY