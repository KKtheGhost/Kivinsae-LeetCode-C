/*
 * @lc app=leetcode id=3 lang=c
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start

int lengthOfLongestSubstring(char * s){
    /* Longest valid none repeat ascii substring's length is 128 */
    int ans=0, tmpAns=0, resCap[128];

    bzero(resCap, sizeof(resCap));
    for (char *c = s; *c; c++) {
        int i = c - s + 1;
        int candiAns = i - resCap[*c];
        int maxAns = (++tmpAns < candiAns) ? tmpAns : candiAns;
        resCap[*c] = i;

        if (maxAns > ans) {
            ans = maxAns;
        }
        tmpAns = maxAns;
    }

    return ans;
}
// @lc code=end
// @lc MEDIUM