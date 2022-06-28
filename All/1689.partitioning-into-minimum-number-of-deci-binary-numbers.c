/*
 * @lc app=leetcode id=1689 lang=c
 *
 * [1689] Partitioning Into Minimum Number Of Deci-Binary Numbers
 */

// @lc code=start
int minPartitions(char * n){
    int len = strlen(n);
    int i = 0, j = len - 1;
    int res = 0;
    while (i <= j)
    {
        res = (res < n[i] - '0')? n[i] - '0' : res;
        res = (res < n[j] - '0')? n[j] - '0' : res;
        if (res == 9) {return res;}
        i++;j--;
    }
    return res;
}
// @lc code=end
// @lc MEDIUM