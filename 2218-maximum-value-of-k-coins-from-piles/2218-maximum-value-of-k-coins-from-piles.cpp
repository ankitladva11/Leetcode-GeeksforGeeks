class Solution {

public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        int n = piles.size();
        vector<int> dp(k + 1);
        dp[0] = 0;

        for(int j = 1; j <= k; j++)
            dp[j] = dp[j - 1] + (j - 1 < piles[n - 1].size() ? piles[n - 1][j - 1] : 0);
        
        for(int i = n - 2; i >= 0; i--)
        {
            vector<int> _dp(k + 1);
            _dp[0] = 0;
            for(int j = 1; j <= k; j++)
            {
                int preSum = 0;
                int currMax = dp[j];
                for(int x = 1; x <= j && x - 1 < piles[i].size(); x++)
                {
                    preSum += piles[i][x - 1];
                    currMax = max(currMax, preSum + dp[j - x]);
                }
                _dp[j] = currMax;
            }
            dp.swap(_dp);
        }

        return dp[k];
    }
};