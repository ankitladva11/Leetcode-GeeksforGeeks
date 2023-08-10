class Solution {
public:
    bool search(vector<int>& nums, int target) {
        bool ans=false;
        for (int i=0;i<nums.size();i++){
            if(nums[i]==target){
                return true;
            }
        }
        return ans;
        
    }
};