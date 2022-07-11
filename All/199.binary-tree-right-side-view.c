/*
 * @lc app=leetcode id=199 lang=c
 *
 * [199] Binary Tree Right Side View
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
void input(struct TreeNode* root, int* returnSize, int* ans, int now){
    if(root == NULL){
        return;
    }
    if(now > *returnSize){
        ans[*returnSize] = root->val;
        *returnSize += 1;
    }
    input(root->right, returnSize, ans, now+1);
    input(root->left, returnSize, ans, now+1);
}

int* rightSideView(struct TreeNode* root, int* returnSize){
    if (root == NULL){
        *returnSize = 0;
        return NULL;
    }
    int* ans = malloc(sizeof(int)*100);
    *returnSize = 0;
    input(root, returnSize, ans, 1);
    return ans;
}
// @lc code=end
// @lc MEDIUM