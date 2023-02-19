class Solution {
public:
    string process(string s){
        int count=1;
        char a=s[0];
        string sol="";
        for(int i=1;i<s.length();i++){
            
            if(a==s[i]){
                count++;
            }
            else{
                sol=sol+to_string(count)+a;
                a=s[i];
                count=1;
            }
        }
    sol=sol+to_string(count)+a;
return sol;
        
        
    }
    string countAndSay(int n) {
        if(n==1){
            return "1";
            
        }
        string sol="11";
        
        for(int i=3;i<=n;i++){
            string b=process(sol);
            sol=b;
        }
        return sol;
    }
};