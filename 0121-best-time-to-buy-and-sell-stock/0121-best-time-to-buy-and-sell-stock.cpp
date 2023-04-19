class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minPrice = INT_MAX;

        for(int i = 0; i < (int)prices.size(); i++){
            minPrice = min(minPrice,prices[i]);
            profit = max(profit,prices[i] - minPrice);
        }
        return profit;
    }
};