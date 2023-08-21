class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int i=n/2;i>=1;i--){                //commented below
            if(n%i==0){                                                             //i is expressing the size of the substring 
                if(s.substr(0,n-i)==s.substr(i))return true;           //rotation approach-->if two substrings from first and last match then we can say they can repeatedly form the string.
            }
        }
        return false;
    }
};