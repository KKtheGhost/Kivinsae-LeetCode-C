/*
 * @lc app=leetcode id=820 lang=c
 *
 * [820] Short Encoding of Words
 *
 * https://leetcode.com/problems/short-encoding-of-words/description/
 *
 * algorithms
 * Medium (55.33%)
 * Likes:    1251
 * Dislikes: 486
 * Total Accepted:    69.8K
 * Total Submissions: 118.6K
 * Testcase Example:  '["time","me","bell"]'
 *
 * A valid encoding of an array of words is any reference string s and array of
 * indices indices such that:
 * 
 * 
 * words.length == indices.length
 * The reference string s ends with the '#' character.
 * For each index indices[i], the substring of s starting from indices[i] and
 * up to (but not including) the next '#' character is equal to words[i].
 * 
 * 
 * Given an array of words, return the length of the shortest reference string
 * s possible of any valid encoding of words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["time", "me", "bell"]
 * Output: 10
 * Explanation: A valid encoding would be s = "time#bell#" and indices = [0, 2,
 * 5].
 * words[0] = "time", the substring of s starting from indices[0] = 0 to the
 * next '#' is underlined in "time#bell#"
 * words[1] = "me", the substring of s starting from indices[1] = 2 to the next
 * '#' is underlined in "time#bell#"
 * words[2] = "bell", the substring of s starting from indices[2] = 5 to the
 * next '#' is underlined in "time#bell#"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["t"]
 * Output: 2
 * Explanation: A valid encoding would be s = "t#" and indices = [0].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 2000
 * 1 <= words[i].length <= 7
 * words[i] consists of only lowercase letters.
 * 
 * 
 */

// @lc code=start
bool isTailSubStr(char *str, char *slice, int lLen, int sLen) {
    for (int i = 0; i < sLen; i++) {
        if (str[lLen - 1 - i] != slice[sLen - 1 - i]) {return false;}
    }
    return true;
}

int minimumLengthEncoding(char ** words, int wordsSize){
    if (wordsSize == 1) {return strlen(words[0]) + 1;}
    int discount = 0, sLen = 0, lLen = 0;
    int res = wordsSize;
    int *mem = malloc(sizeof(int) * wordsSize); memset(mem, 0, sizeof(int)*wordsSize);
    for (int i = 0; i < wordsSize; ++i) {
        sLen = strlen(words[i]);
        res += sLen;
        for (int j = 0; j < i; ++j) {
            lLen = strlen(words[j]);
            if (sLen <= lLen) {
                if (isTailSubStr(words[j], words[i], lLen, sLen) && mem[i] == 0) {
                    discount = discount + sLen + 1;
                    mem[i]++;
                    goto end;
                }
            }
            else {
                if (isTailSubStr(words[i], words[j], sLen, lLen) && mem[j] == 0) {
                    discount = discount + lLen + 1;
                    mem[j]++;
                    goto end;
                }
            }
        }
        end:;
    }
    return res - discount;
}
// @lc code=end
// @lc MEDIUM