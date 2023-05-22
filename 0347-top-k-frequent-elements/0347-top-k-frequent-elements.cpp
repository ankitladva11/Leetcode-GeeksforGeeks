class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> hash;

        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }

        vector<pair<int,int>> s;

        for(auto &i:hash){
            s.push_back({i.second,i.first});
        }

        sort(s.begin(),s.end(),greater<pair<int,int>>());

        vector<int> ans; 

        for(int i=0;i<k;i++){
            ans.push_back(s[i].second);
        }

        return ans;
    }
};