/*
 * @lc app=leetcode id=110 lang=c
 *
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (47.01%)
 * Likes:    6188
 * Dislikes: 330
 * Total Accepted:    804.9K
 * Total Submissions: 1.7M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, determine if it is height-balanced.
 * 
 * For this problem, a height-balanced binary tree is defined as:
 * 
 * 
 * a binary tree in which the left and right subtrees of every node differ in
 * height by no more than 1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2,2,3,3,null,null,4,4]
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = []
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 5000].
 * -10^4 <= Node.val <= 10^4
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

int depth (struct TreeNode* root, bool* result) {
    if (root == NULL) {return 0;}
    int l = depth(root->left, result);
    int r = depth(root->right, result);
    if (abs(l - r) > 1)
        (*result) = false;
    return 1 + ((l > r)? l : r);
}

bool isBalanced(struct TreeNode* root){
    bool result = true;
    depth(root, &result);
    return result;
}
// @lc code=end
// @lc EASY