/*
 * @lc app=leetcode id=102 lang=c
 *
 * [102] Binary Tree Level Order Traversal
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **result, size;
void depth(struct TreeNode* root, int counter){
    if(root == NULL) {
        if(counter > size) size = counter;
        return;
    }
    depth(root->left, counter + 1);
    depth(root->right, counter + 1);
}

void travel(struct TreeNode* root, int** returnColumnSizes, int level){
    if(root == NULL) return;
    result[level][(*returnColumnSizes)[level]++] = root->val;
    travel(root->left, returnColumnSizes, level + 1);
    travel(root->right, returnColumnSizes, level + 1);
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    size = 0;
    depth(root, 0);
    result = (int**)malloc(sizeof(int*) * size);
    for(int i = 0; i < size; i++) {
        result[i] = (int*)malloc(sizeof(int) * 256);
    }
    *returnColumnSizes = (int*)calloc(size, sizeof(int));
    travel(root, returnColumnSizes, 0);
    *returnSize = size;
    return result;
}
// @lc code=end
// @lc MEDIUM