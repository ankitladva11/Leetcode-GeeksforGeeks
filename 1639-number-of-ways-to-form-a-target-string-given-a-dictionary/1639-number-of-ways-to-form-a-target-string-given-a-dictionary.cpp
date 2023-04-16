class Solution {
public:
int M=1e9+7;
long long int solve(vector<string>& words, string target,int i,int j,vector<vector<int>>&dp,vector<vector<int>>&freq){
    if(j==target.size())return 1;
    if(i==words[0].size()||words[0].size()-i<target.size()-j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int n=words.size();
    long long int cnt=0;
    // for(int ind=0;ind<n;ind++){
    //     if(words[ind][i]==target[j])cnt+=solve(words,target,i+1,j+1,dp)%M;
    // }
    long long int curr=target[j]-'a';
    cnt+=freq[i][curr]*solve(words,target,i+1,j+1,dp,freq)%M;
    cnt+=solve(words,target,i+1,j,dp,freq)%M;
    return dp[i][j]=cnt%M;
}
    int numWays(vector<string>& words, string target) {
        int n=target.size(),m=words[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        vector<vector<int>>freq(m+1,vector<int>(26,0));

        for(int i=0;i<words.size();i++){
            for(int j=0;j<m;j++){
                int curr=words[i][j]-'a';
                freq[j][curr]++;
            }
        }
        return solve(words,target,0,0,dp,freq);
    }
};