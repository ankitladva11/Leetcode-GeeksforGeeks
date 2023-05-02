class Solution {
public:
    int arraySign(vector<int>& nums) {
//         for(auto:x){
            
//         }
        int pdt=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                return 0;
            }
            if(nums[i]>0){
                pdt*=1;
            }
            else{
                 pdt*=-1;
            }
            // pdt=pdt*nums[i];
        }
        if(pdt>0){
            return 1;
        }
        else{
            return -1;
        }
    }
};