class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector <int> sol(3);
        for (int i=0;i<nums.size();i++){
            sol[nums[i]]++;
        }
        int size=0;
        for (int i=size;i<sol[0];i++){
            nums[i]=0;
            size++;
        }
        for (int i=sol[0];i<sol[0]+sol[1];i++){
            nums[i]=1;
                        size++;

        }
        for (int i=sol[0]+sol[1];i<sol[0]+sol[1]+sol[2];i++){
            nums[i]=2;
        }
        
        
    }
};