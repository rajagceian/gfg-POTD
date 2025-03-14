class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        vector<int> dp(sum + 1, 0);
        dp[0] = 1; // There's one way to make sum=0 (by choosing nothing)

        for (int coin : coins) { // Consider each coin
            for (int j = coin; j <= sum; j++) { // Update dp array
                dp[j] += dp[j - coin];
            }
        }
        return dp[sum];
    }
};
