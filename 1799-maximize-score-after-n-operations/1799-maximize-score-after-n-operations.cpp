class Solution {
public:
 int n;
  int solve(vector<int>&nums,vector<bool>&visited,int op,unordered_map<vector<bool>,int>&mp)
  { 
      if(mp.find(visited) !=mp.end()) return mp[visited];
      int maxscore=0;
      for(int i=0;i<=n-2;i++)
      {
          if(visited[i]==true) continue;
          for(int j=i+1;j<n;j++)
          {
              if(visited[j]==true) continue;
              visited[i]=true;
              visited[j]=true;
              int cscore=op*__gcd(nums[i],nums[j]);
              int rscore=solve(nums,visited,op+1,mp);
              maxscore=max(maxscore,cscore+rscore);
              visited[i]=false;
              visited[j]=false;
          }

      }
      return mp[visited]=maxscore;
  }
    int maxScore(vector<int>& nums) {
        n=nums.size();
        vector<bool>visited(n,false);
        unordered_map<vector<bool>,int>mp;
        return solve(nums,visited,1,mp);
        
    }
};
