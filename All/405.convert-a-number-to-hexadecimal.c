/*
 * @lc app=leetcode id=405 lang=c
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start


char * toHex(int num){
    char *res = malloc(sizeof(char)*9);
    sprintf(res, "%x", num);
    return res;
}
// @lc code=end
// @lc EASY