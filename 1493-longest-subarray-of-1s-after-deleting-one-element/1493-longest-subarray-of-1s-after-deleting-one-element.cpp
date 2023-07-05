class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int numberOfZeroes=0;
        int ans=0;
        int start=0;
        for(int i=0;i<nums.size();i++){
            numberOfZeroes += (nums[i]==0);
            while (numberOfZeroes > 1){
                numberOfZeroes -= (nums[start++]==0);
            }
            ans=max(ans,i-start);
        }
        return ans;
    }
};