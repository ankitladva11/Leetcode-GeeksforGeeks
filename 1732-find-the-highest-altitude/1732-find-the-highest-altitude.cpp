class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_gain=0;
        int sum=0;
        for(int i=0;i<gain.size();i++){
            sum+=gain[i];
            max_gain=max(max_gain,sum);
        }
        return max_gain;
    }
};