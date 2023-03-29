class Solution {
public:

    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(), s.end());
        int ans = 0, n=s.size(), time, sum;
        for(int i=n-1;i>=0;i--){
            time = 1, sum = 0;
            for(int j=i;j<n;j++,time++){
                sum += (s[j]*time);
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};