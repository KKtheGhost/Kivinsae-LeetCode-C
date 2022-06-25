/*
 * @lc app=leetcode id=144 lang=c
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (62.86%)
 * Likes:    4311
 * Dislikes: 133
 * Total Accepted:    985.1K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the preorder traversal of its nodes'
 * values.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,null,2,3]
 * Output: [1,2,3]
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
 * 
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
void PreOrder(struct TreeNode* root, int* res, int* i) {
    if (root == NULL) {return;}
    res[(*i)++] = root->val;
    PreOrder(root->left, res, i);
    PreOrder(root->right, res, i);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int *res = malloc(sizeof(int)*100); memset(res, 0, sizeof(int));
    PreOrder(root, res, returnSize);
    return res;
}
// @lc code=end
// @lc EASY