//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

// class Solution
// {
//     public:
//      int dp[1001][1001] ;
//   Solution(){
//       for( int i = 0 ; i < 1001 ; i++ )
//           for( int j = 0 ; j < 1001 ; j++ )
//               dp[i][j] = -1 ;
//   }
//     //Function to find the length of longest common subsequence in two strings.
//     // int solvedp()
//     int lcs(int n, int m, string s1, string s2)
//     {
//         // your code here
//         // vector<vector<int>> dp(m,vector<int>(n,-1));
        
//         if(m==0 || n==0){
//             return dp[n][m]=0;
//         }
//         if(dp[n][m]!=-1){
//             return dp[n][m];
//         }
//         if(s1[n-1]==s2[m-1]){
//             return dp[n][m]=1+lcs(n-1,m-1,s1,s2);
//         }
//         else{
//             return dp[n][m]=max(lcs(n,m-1,s1,s2),lcs(n-1,m,s1,s2));
//         }
        
//     }
// };
class Solution
{
   public:
    int solveDP(string s1, string s2, int n, int m){
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][m];
    }
    
    
    int lcs(int n, int m, string s1, string s2)
    {
        // vector<vector<int>> memo(n+1, vector<int>(m+1, -1)) ;
        // return solve(s1, s2, n, m, memo);
        return solveDP(s1, s2, n, m);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends