/*
 * @lc app=leetcode id=121 lang=c
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (54.17%)
 * Likes:    17191
 * Dislikes: 564
 * Total Accepted:    2.3M
 * Total Submissions: 4.2M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i^th day.
 * 
 * You want to maximize your profit by choosing a single day to buy one stock
 * and choosing a different day in the future to sell that stock.
 * 
 * Return the maximum profit you can achieve from this transaction. If you
 * cannot achieve any profit, return 0.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: prices = [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Note that buying on day 2 and selling on day 1 is not allowed because you
 * must buy before you sell.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transactions are done and the max profit =
 * 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= prices.length <= 10^5
 * 0 <= prices[i] <= 10^4
 * 
 * 
 */

// @lc code=start


int maxProfit(int* prices, int pricesSize){
    if (pricesSize == 1) {return 0;}
    int res = 0;
    int max = prices[pricesSize - 1];
    for (int i = pricesSize - 1; i >= 0; --i) {
        max = (max <= prices[i])? prices[i] : max;
        res = (max - prices[i] > res)? max - prices[i] : res;
    }
    return res;
}
// @lc code=end
// @lc EASY