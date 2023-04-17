class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector <bool> sol(candies.size());
        int max=*max_element(candies.begin(),candies.end());

        for(int i=0;i<candies.size();i++){
            candies[i]+=extraCandies;
            if(candies[i]>=max){
                sol[i]=true;
            }
                
        }
        return sol;
    }
};