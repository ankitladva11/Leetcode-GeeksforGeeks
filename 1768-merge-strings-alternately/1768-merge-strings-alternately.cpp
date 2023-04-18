class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1=word1.length();
        int n2=word2.length();
        int n=min(n1,n2);
        string sol="";
        for(int i=0;i<n;i++){
            sol=sol+word1[i]+word2[i];
        }
        if(n1>n){
            for(int i=n;i<n1;i++){
            sol=sol+word1[i];
        }
        }
        if(n2>n){
            for(int i=n;i<n2;i++){
            sol=sol+word2[i];
        }
        }
return sol;
    }
};