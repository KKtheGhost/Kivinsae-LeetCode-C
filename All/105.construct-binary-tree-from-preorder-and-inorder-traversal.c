/*
 * @lc app=leetcode id=105 lang=c
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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


struct TreeNode* buildTree_r(int* preorder, int* inorder, int preStart, int preEnd,
					   int inStart, int inEnd) {
   
	if(preStart > preEnd || inStart > inEnd)
		return NULL;

	struct TreeNode* root = malloc(sizeof(struct TreeNode));
	root->val = preorder[preStart];
	
	int in_rootidx; // Find root in inorder
	for(int i = inStart; i <= inEnd; i++) {
		if(inorder[i] == root->val) {
			in_rootidx = i;
			break;
		}
	}
	
	root->left  = buildTree_r(preorder, inorder, preStart + 1, preEnd, inStart,
                             in_rootidx - 1);
	root->right = buildTree_r(preorder, inorder, preStart+in_rootidx-inStart + 1,
						      preEnd, in_rootidx + 1, inEnd);

	return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize,
					int* inorder, int inorderSize) { 
	if(inorder == NULL || preorder == NULL)
		return NULL;

	return buildTree_r(preorder, inorder, 0, preorderSize - 1, 0, inorderSize - 1);
}
// @lc code=end
// @lc MEDIUM