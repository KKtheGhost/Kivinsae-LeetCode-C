/*
 * @lc app=leetcode id=89 lang=c
 *
 * [89] Gray Code
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize){
    int i = 1<<n;
    *returnSize = 1<<n;
    int *res = calloc(i, sizeof(int));
    while (--i >= 0) {res[i] = i^(i>>1);}
    return res;
}
// @lc code=end
// @lc MEDIUM