/*
 * @lc app=leetcode id=746 lang=c
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
int min(int a, int b){
    if (a < b) {return a;} else {return b;}
}
int minCostClimbingStairs(int* cost, int costSize){
    int p1 = cost[0], p2 = cost[1];
    int tmp1, tmp2;
    for (int i = 2; i < costSize; ++i) {
        tmp1 = p1+cost[i]; tmp2 = p2+cost[i];
        p1 = p2; p2 = min(tmp1, tmp2);
    }
    return min(p1, p2);
}
// @lc code=end
// @lc EASY