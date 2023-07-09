//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void f(string s,vector<string>&ans,int i){
       // 
       if(i>=s.size()){
           ans.push_back(s);
           return;
       }
       for(int j=i;j<s.size();j++){
          
               swap(s[i],s[j]); 
           
          
           f(s,ans,i+1);
           
           swap(s[i],s[j]);
       }
       
        
    }
        vector<string>find_permutation(string S)
        {
            // Code here there
            vector<string>ans;
            f(S,ans,0);
            set<string>st;
            for(int i=0;i<ans.size();i++ ){
                st.insert(ans[i]);
            }
            ans.clear();
           for(auto x:st){
               ans.push_back(x);
           }
            sort(ans.begin(),ans.end());
            return ans;
           
            
        }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends