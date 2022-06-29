/*
 * @lc app=leetcode id=404 lang=c
 *
 * [404] Sum of Left Leaves
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
void leftLeaf(struct TreeNode* root, int* sum) {
    if (root == NULL) {return;}
    else {
        if (root->right != NULL) {
            leftLeaf(root->right, sum);
        }
        if (root->left != NULL) {
            if (root->left->left == NULL && root->left->right == NULL) {
                (*sum) += root->left->val;
            }
            else {
                leftLeaf(root->left, sum);
            }
        }
    }
}
int sumOfLeftLeaves(struct TreeNode* root){
    int sum = 0;
    leftLeaf(root, &sum);
    return sum;
}
// @lc code=end
// @lc EASY