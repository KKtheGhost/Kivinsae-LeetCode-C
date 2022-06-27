/*
 * @lc app=leetcode id=5 lang=c
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start

char * longestPalindrome(char * s){
    int length = strlen(s);
    if (length == 0 || length == 1) {return s;}
    int palinLength, sttIdx, ptr;
    palinLength = 1; sttIdx = ptr = 0;

    while (ptr < length)
    {
        int i1 = ptr, i2 = ptr;

        while (i2 < length && s[i2] == s[i2 + 1])
        {
            ++i2;
        }
        while (0 < i1 && i2 < length - 1 && s[i1 - 1] == s[i2 + 1])
        {
            --i1;
            ++i2;
        }
        if (i2 - i1 + 1 > palinLength) {
            palinLength = i2 - i1 + 1;
            sttIdx = i1;
        }
        ++ptr;
    }
    char* res = (char *)malloc((palinLength + 1) * sizeof(char));
    memcpy(res, &s[sttIdx], palinLength);
    res[palinLength] = '\0';
    return res;
}
// @lc code=end
// @lc MEDIUM