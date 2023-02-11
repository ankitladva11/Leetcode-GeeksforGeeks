class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int pele=nums[0];
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                return nums[i];
            }
        }
        // vector <int> vec(n,0);
        // for (int i=0;i<n;i++){
        //     vec[nums[i]]++;
        // }
        // for (int i=0;i<n;i++){
        //     if(vec[i]>1){
        //         pele=vec[i];
        //         break;
        //     }
        // }
        return -1;
    }
};