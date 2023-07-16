//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        int sl=s.length();
        int tl=t.length();
        int sol[sl+1][tl+1];

        for(int i=0;i<=sl;i++){
            sol[i][0]=i;
        }
          for(int i=0;i<=tl;i++){
            sol[0][i]=i;
        }

          for(int i=1;i<=sl;i++){
               for(int j=1;j<=tl;j++){
                       if(s[i-1]==t[j-1]){
                           sol[i][j]=sol[i-1][j-1];
                       }
                       else{
                           sol[i][j]=1+min(sol[i-1][j-1],min(sol[i][j-1],sol[i-1][j]));
                       }
               }
        }
        return sol[sl][tl];
        
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends