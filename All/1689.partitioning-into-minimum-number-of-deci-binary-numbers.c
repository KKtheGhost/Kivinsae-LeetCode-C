/*
 * @lc app=leetcode id=1689 lang=c
 *
 * [1689] Partitioning Into Minimum Number Of Deci-Binary Numbers
 */

// @lc code=start


int minPartitions(char * n){
    int res = 0, len = strlen(n);
    for (int i = 0; i < len; i++) {
        res = (res < (n[i] - '0')%10)? (n[i] - '0')%10 : res;
    }
    return res;
}
// @lc code=end
// @lc MEDIUM