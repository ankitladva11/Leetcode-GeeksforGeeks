class Solution {
public:
    unordered_map<string, int> dpMap;

    bool isScramble(string s1, string s2) {
        //base case
        if(s1.compare(s2) == 0)return true;
        if(s1.length() <= 1)return false;

        //memoization
        if(dpMap.find(s1 + " " + s2) != dpMap.end()){
            return dpMap[s1 + " " + s2];
        }

        //recursive case
        int len = s1.length();
        bool flag = false;

        for(int i = 1; i <= len - 1; i++)
        {
            bool resultOfSwappingDone = (isScramble(s1.substr(0, i), s2.substr(len - i, i))) and (isScramble(s1.substr(i, len - i), s2.substr(0, len - i)));

             bool resultOfSwappingNotDone = (isScramble(s1.substr(0, i), s2.substr(0, i))) and (isScramble(s1.substr(i, len - i), s2.substr(i, len - i)));

             if(resultOfSwappingDone or resultOfSwappingNotDone){
                 flag = true;
                 break;
             }
        }

        return dpMap[s1 + " " + s2] = flag;
    }
};