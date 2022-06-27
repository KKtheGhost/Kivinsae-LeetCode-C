/*
 * @lc app=leetcode id=101 lang=c
 *
 * [101] Symmetric Tree
 *
 * https://leetceode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (51.81%)
 * Likes:    9770
 * Dislikes: 240
 * Total Accepted:    1.3M
 * Total Submissions: 2.5M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given the root of a binary tree, check whether it is a mirror of itself
 * (i.e., symmetric around its center).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,2,3,4,4,3]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2,2,null,3,null,3]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 1000].
 * -100 <= Node.val <= 100
 * 
 * 
 * 
 * Follow up: Could you solve it both recursively and iteratively?
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
void Compare(struct TreeNode* p, struct TreeNode* q, bool* res) {
    if ((!p) + (!q) == 1) {(*res)*=0; return;}
    if (p != NULL) {
        Compare(p->left, q->left, res);
        (*res)*=!!(p->val == q->val);
        Compare(p->right, q->right, res);
    }
}
void mirrorBtree(struct TreeNode* btree) {
    if (btree != NULL) {
        struct TreeNode* temp;
        temp = btree->left;
        btree->left = btree->right;
        btree->right = temp;
        mirrorBtree(btree->left);
        mirrorBtree(btree->right);
    }
}

bool isSymmetric(struct TreeNode* root){
    mirrorBtree(root->right);
    bool res = true; Compare(root->left, root->right, &res); return res;
}
// @lc code=end
// @lc EASY