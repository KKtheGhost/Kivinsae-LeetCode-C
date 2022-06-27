/*
 * @lc app=leetcode id=11 lang=c
 *
 * [11] Container With Most Water
 */

// @lc code=start


int maxArea(int* height, int heightSize){
    int i = 0, j = heightSize - 1;
    int res = ((height[i] > height[j]) ? height[j] : height[i]) * (j - i);
    while (i < j)
    {
        int calH = (height[i] > height[j]) ? height[j] : height[i];
        res = (calH*(j - i) > res) ? calH*(j - i) : res;
        if (height[i] < height[j]) {++i;}
        else {--j;}
    }
    return res;
}
// @lc code=end
// @lc MEDIUM