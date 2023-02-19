class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string temp=countAndSay(n-1);
        int i=0;
        string str="";
        while(i<temp.size()){
            char ch=temp[i];
            int count=0;
            while(temp[i]==ch){
                count++;
                i++;
            }
            str+=to_string(count);
            str+=ch;
        }
        return str;
    }
};