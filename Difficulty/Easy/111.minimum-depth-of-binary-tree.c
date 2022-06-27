/*
 * @lc app=leetcode id=111 lang=c
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (42.69%)
 * Likes:    4254
 * Dislikes: 965
 * Total Accepted:    775.6K
 * Total Submissions: 1.8M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [2,null,3,null,4,null,5,null,6]
 * Output: 5
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 10^5].
 * -1000 <= Node.val <= 1000
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
    depth++;
    if (root->left == NULL && root->right == NULL) {
        (*res) = (depth < (*res))? depth : (*res);
    }
    else {
        if (root->left != NULL && depth < (*res)) {GetDepth(root->left, depth, res);}
        if (root->right != NULL && depth < (*res)) {GetDepth(root->right, depth, res);}
    }
}
int minDepth(struct TreeNode* root){
    if (root == NULL) return 0;
    int res = 10001, depth = 0;
    GetDepth(root, depth, &res);
    return res;
}
// @lc code=end
// @lc EASY