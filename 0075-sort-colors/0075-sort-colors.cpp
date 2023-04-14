class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> m;
        for(auto i : nums)
        {
            m[i]++;
        }
        nums.clear();
        for(auto i : m)
        {
            nums.push_back(i.first);
            i.second--;
            if(i.second>=1)
            {
                while(i.second--)
                {
                    nums.push_back(i.first);
                }
            }
        }
    }
};