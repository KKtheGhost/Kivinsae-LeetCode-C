/*
 * @lc app=leetcode id=94 lang=c
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Easy (71.04%)
 * Likes:    8009
 * Dislikes: 369
 * Total Accepted:    1.5M
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the inorder traversal of its nodes'
 * values.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,null,2,3]
 * Output: [1,3,2]
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
 * The number of nodes in the tree is in the range [0, 100].
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
void InOrder(struct TreeNode* root, int* res, int* returnSize) {
    if (root != NULL) {
        InOrder(root->left, res, returnSize);
        res[(*returnSize)++]=root->val;
        InOrder(root->right, res, returnSize);
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *res = malloc(sizeof(int)*100);
    *returnSize = 0;
    InOrder(root, res, returnSize);
    return res;
}
// @lc code=end
// @lc EASY