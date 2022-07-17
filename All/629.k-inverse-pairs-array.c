/*
 * @lc app=leetcode id=629 lang=c
 *
 * [629] K Inverse Pairs Array
 */

// @lc code=start
#define MOD 1000000007
int kInversePairs(int n, int k) {
    int dp[2][1001] = { 1 };
    for (int N = 1; N <= n; ++N)
        for (int K = 0; K <= k; ++K) {
            dp[N % 2][K] = (dp[(N - 1) % 2][K] + (K > 0 ? dp[N % 2][K - 1] : 0)) % MOD;
            if (K >= N)
                dp[N % 2][K] = (MOD + dp[N % 2][K] - dp[(N - 1) % 2][K - N]) % MOD;
        }
    return dp[n % 2][k];
}
// @lc code=end
// @lc HARD