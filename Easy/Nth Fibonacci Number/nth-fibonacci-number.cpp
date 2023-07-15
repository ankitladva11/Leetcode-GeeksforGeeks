//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int mod=1e9+7;
  long long int solve(long long int n , vector <long long int>&dp){
      if(n<=1)return n;
      if(dp[n]!=-1)return dp[n];
      return dp[n]=(solve(n-1,dp)+solve(n-2,dp))%mod;
  }
  long long  int nthFibonacci(int n){
        // code here
         vector<long long int> memo(n+1,-1);
return solve(n,memo);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends