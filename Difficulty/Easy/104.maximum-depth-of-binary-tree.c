/*
 * @lc app=leetcode id=104 lang=c
 *
 * [104] Maximum Depth of Binary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (72.07%)
 * Likes:    7357
 * Dislikes: 130
 * Total Accepted:    1.7M
 * Total Submissions: 2.4M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return its maximum depth.
 * 
 * A binary tree's maximum depth is the number of nodes along the longest path
 * from the root node down to the farthest leaf node.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,null,2]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 10^4].
 * -100 <= Node.val <= 100
 * 
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
void GetDepth(struct TreeNode* root, int depth, int* res) {
    if (root != NULL) {
        depth += 1;
        (*res) = ((*res) < depth) ? depth : (*res);
        GetDepth(root->left, depth, res);
        GetDepth(root->right, depth, res);
    }
}

int maxDepth(struct TreeNode* root){
    if (root == NULL) {return 0;}
    int depth = 0; int res = 0;
    GetDepth(root, depth, &res);
    return res;
}
// @lc code=end
// @lc EASY