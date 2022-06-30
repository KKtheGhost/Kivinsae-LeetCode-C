/*
 * @lc app=leetcode id=462 lang=c
 *
 * [462] Minimum Moves to Equal Array Elements II
 */

// @lc code=start
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int minMoves2(int* nums, int numsSize){
    int res = 0, i = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    while (i < numsSize) {
        res += abs(nums[i] - nums[numsSize/2]); ++i;
    }
    return res;
}
// @lc code=end
// @lc MEDIUM