class Solution {
public:
    int maxProfit(vector<int>& prices) {
          int profit = 0;
        int minPrice = INT_MAX;

        for(int i = 0; i < (int)prices.size(); i++){
            minPrice = min(minPrice,prices[i]);
            profit = max(profit,prices[i] - minPrice);
        }
        return profit;}
//       int minn=INT_MAX;
//         int ind;
//         int ind_prev;
//         int maxx=0;
//         for(int i=0;i<prices.size();i++){
//             if(minn>prices[i] && (prices[i]!=0)){
//                 ind_prev=ind;
//                 minn=prices[i];
//                 ind=i;
//             }
//         }
//         if(ind==(prices.size()-1)){
//             for(int i=ind_prev+1;i<prices.size();i++){
//             maxx=max(prices[i]-prices[ind_prev],maxx);
//         }
//             return maxx;
//         }
//          for(int i=ind+1;i<prices.size();i++){
//             maxx=max(prices[i]-prices[ind],maxx);
//         }
        
        
//         return maxx;
//     }
    
};