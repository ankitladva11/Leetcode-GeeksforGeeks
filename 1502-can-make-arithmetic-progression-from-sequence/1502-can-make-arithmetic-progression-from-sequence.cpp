class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        vector<int> ans;
        sort(arr.begin(),arr.end());
        if(arr.size()<2){
            return true;
        }
        int diff=arr[1]-arr[0];
        for(int i=1;i<arr.size();i++){
            if(diff!=(arr[i]-arr[i-1])){
                return false;
            }
        }
        return true;
    }
};