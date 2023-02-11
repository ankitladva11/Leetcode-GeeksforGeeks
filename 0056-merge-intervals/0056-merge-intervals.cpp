class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int>> nonoverlap(intervals.size());
//         vector<int> arr;
//         for(int i=1;i<intervals.size();i++)
//         {
//             if(intervals[i][1]<=intervals[i-1][1])
//             {
//                 arr={intervals[i-1][0],intervals[i][1]};
//                 nonoverlap[i].push_back(arr);
//             }
//             else{
//                  nonoverlap[i].push_back(intervals[i]);
//             }
//         }    
// //         for(auto x:nonoverlap){
            
// //             cout<<x;
// //         }
//         return nonoverlap;
        sort(intervals.begin(),intervals.end());
		int n=intervals.size();
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(ans[ans.size()-1][1]<intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else{
                ans[ans.size()-1][1]=max(ans[ans.size()-1][1],intervals[i][1]);
            }
        }
        return ans;
    }
};