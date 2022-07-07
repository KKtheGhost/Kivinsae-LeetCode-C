/*
 * @lc app=leetcode id=97 lang=c
 *
 * [97] Interleaving String
 */

// @lc code=start

bool dp[200];
bool isInterleave(char * s1, char * s2, char * s3){
    bool res1 = true, res2 = true;
    int len1 = strlen(s1), len2 = strlen(s2), len3 = strlen(s3);
    if (len1 + len2 != len3) {return false;}
    dp[0] = true;
    for(int j = 1; j <= len2; j++)
        dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]);
    for(int i = 1; i <= len1; i++){
        char cur = s1[i - 1];
        dp[0] = dp[0] && (s1[i - 1] == s3[i - 1]);
        for(int j = 1; j <= len2; j++)
            dp[j] = (dp[j] && cur == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
    }
    return dp[len2];
}
// @lc code=end
// @lc MEDIUM