class Solution {
public:
    string func(string s) {
        string res = "";
        auto itr = s.begin();
        while(itr !=s.end()) {
            char c = *itr; int num =0;
            while(itr != s.end() and *itr == c) itr++, num++; 
            res += to_string(num);
            res.push_back(c);
        }
        return res;
    }
    string countAndSay(int n) {
        n--;
        string res = "1";
        while(n--) res = func(res);
        return res;
    }
};