/*
 * @lc app=leetcode id=15 lang=c
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (31.28%)
 * Likes:    18329
 * Dislikes: 1765
 * Total Accepted:    2M
 * Total Submissions: 6.4M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * 
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Example 2:
 * Input: nums = []
 * Output: []
 * Example 3:
 * Input: nums = [0]
 * Output: []
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (numsSize < 3) 
        return NULL;
    int i, high, low, sum;
    int** result = (int**)malloc(sizeof(int)*numsSize*(numsSize-1)/2);
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    for (i = 0; nums[i] <= 0 && i < numsSize-2;)
    {
        low = i + 1;
        high = numsSize - 1;
        while (low < high)
        {
            sum = nums[low] + nums[high] + nums[i];
            if (sum > 0)
                high--;
            else if (sum < 0)
                low++;
            else
            {
                *returnSize += 1;
                result[*returnSize-1] = (int*)malloc(sizeof(int)*3);
                result[*returnSize-1][0] = nums[i];
                result[*returnSize-1][1] = nums[low];
                result[*returnSize-1][2] = nums[high];
                // avoid duplication
                do high--; while (nums[high]==nums[high+1] && low < high);
            }
        }
        // avoid duplication
        do i++; while (nums[i]==nums[i-1] && i < numsSize-2);
    }
    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
    for (i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = 3;
    return result;
}
// @lc code=end
// @lc MEDIUM