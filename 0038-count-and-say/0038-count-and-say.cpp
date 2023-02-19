class Solution {
public:
    string countAndSay(int n) {
        

        string s="1";
        if(n==1) return s;
        for(int i=1;i<n;i++){
            //counting 
            string temp="";
            vector<pair<char,int>> v;
            for(int j=0;j<s.size();j++){
                char num=s[j];
                // cout<<num<<endl;
                int count=1;
                while(s[j+1]==num and j<s.size()){
                    j++;
                    count++;
                }
                
                v.push_back(make_pair(num,count));
            }
            for(auto it:v){
                char num1=it.first;
                int c=it.second;
                temp+=to_string(c)+num1;
            }
            cout<<temp<<endl;
            s=temp;
        }
        return s;
    }
};