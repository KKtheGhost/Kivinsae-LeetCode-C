/*
 * @lc app=leetcode id=7 lang=c
 *
 * [7] Reverse Integer
 */

// @lc code=start
#include <limits.h>

int reverse(int x){
    if (-2 < x && x < 2) {return x;}
    long long res = 0;
    while (x != 0)
    {
        res = res * 10 + x%10;
        x = x/10;
    }
    #include <limits.h>
    return (res < INT_MIN || res > INT_MAX) ? 0 : res;
}

// @lc code=end
// @lc MEDIUM