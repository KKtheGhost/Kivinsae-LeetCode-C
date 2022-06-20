/*
 * @lc app=leetcode id=46 lang=c
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (72.73%)
 * Likes:    11053
 * Dislikes: 197
 * Total Accepted:    1.2M
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an array nums of distinct integers, return all the possible
 * permutations. You can return the answer in any order.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * Example 3:
 * Input: nums = [1]
 * Output: [[1]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
 * 
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void setNum(int **res, int *res_idx, int* nums, int numsSize, int level) {
    if (level == (numsSize - 1)) {
        memcpy(res[(*res_idx)++], nums, numsSize*sizeof(int));
    }
    else {
        for (int i=level; i <= (numsSize-1); ++i) {
            swap(&nums[level], &nums[i]);
            setNum(res, res_idx, nums, numsSize, level+1);
            swap(&nums[level], &nums[i]);
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int pSize = 1;
    for (int i=numsSize; 1 <= i; --i) {
        pSize *= i;
    }

    int** res = malloc(sizeof(int*)*pSize);
    for(int i=0; i < pSize; i++) {
        res[i] = malloc(sizeof(int)*numsSize);
    }

    int *resCol = malloc(sizeof(int)*pSize);
    for(int i=0; i < pSize; i++) {
        returnColumnSizes[i] = numsSize;
    }
    *returnColumnSizes = resCol;

    int res_idx = 0;
    setNum(res, &res_idx, nums, numsSize, 0);
    *returnSize = res_idx;

    return res;
}
// @lc code=end
// @lc MEDIUM