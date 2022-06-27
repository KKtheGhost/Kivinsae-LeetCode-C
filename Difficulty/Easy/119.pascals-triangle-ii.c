/*
 * @lc app=leetcode id=119 lang=c
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (57.89%)
 * Likes:    2709
 * Dislikes: 273
 * Total Accepted:    540.5K
 * Total Submissions: 930K
 * Testcase Example:  '3'
 *
 * Given an integer rowIndex, return the rowIndex^th (0-indexed) row of the
 * Pascal's triangle.
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it as shown:
 * 
 * 
 * Example 1:
 * Input: rowIndex = 3
 * Output: [1,3,3,1]
 * Example 2:
 * Input: rowIndex = 0
 * Output: [1]
 * Example 3:
 * Input: rowIndex = 1
 * Output: [1,1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= rowIndex <= 33
 * 
 * 
 * 
 * Follow up: Could you optimize your algorithm to use only O(rowIndex) extra
 * space?
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    if (rowIndex > 33) {return NULL;}
    int *former = (int *)malloc(sizeof(int) * 34); former[0] = former[1] = 1;
    int *res = (int *)malloc(sizeof(int) * 34);
    if (rowIndex == 0) {*returnSize = 1; return former;}

    for (int i = 1; i <= 33; ++i) {
        *returnSize = i + 1;
        res[0] = res[i] = 1;
        if (i >= 2) {
            for (int j = 1; j < i; ++j) {
                res[j] = former[j-1] + former[j];
            }
        }
        if (i == rowIndex) {return res;}
        else {memcpy(former, res, sizeof(int) * (i+1));}
    }
    return res;
}
// @lc code=end
// @lc EASY