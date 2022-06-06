/*
 * @lc app=leetcode id=3 lang=c
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
int lengthOfLongestSubstring(char * s){
    /* border situation */
    int sl = strlen(s);
    if (sl == 0 || sl == 1) {return sl;}
    /* function start */
    int *count[128]; int ans = 1;
    /* Init Cap */
    bzero(count, sizeof(count));
    for (int i = 0; i < sl - ans; ++i) {
        ++count[s[i]];
        for (int j = i + 1; j < sl; ++j) {
            /* Common case */
            if (count[s[j]] != 0) {ans = (j - i > ans) ? j - i : ans; goto jump;}
            else {++count[s[j]];}
            /* End of str case */
            if (j == sl - 1) {ans = (j - i + 1 > ans) ? j - i + 1 : ans;}
        }
        jump:bzero(count, sizeof(count));
    }
    return ans;
}
// @lc code=end
// @lc MEDIUM