class Solution {
    
    int bit[100005];
    
    void update(int pos, int n, int val) {
        pos++;
        for ( ; pos <= n ; pos += (pos & (-pos)))
            bit[pos] += val;
    }
    
    int query(int pos) {
        pos++;
        
        int val = 0;
        for ( ; pos > 0 ; pos -= (pos & (-pos)))
            val += bit[pos];
        
        return val;
    }
    
public:
    int countRangeSum(vector<int>& nums, long long int lower, long long int upper) {
        int n = nums.size();
        
        long long int psum = 0;
        vector<long long int> sums;
        for (int x : nums) {
            psum += x;
            sums.push_back(psum);
        }
                        
        sort(sums.begin(), sums.end());
        
        unordered_map<int, bool> visited;
        unordered_map<long long int, int> position;
        
        for (int i = 0 ; i < n ; i++) {
            if (!visited[sums[i]]) {
                visited[sums[i]] = true;
                position[sums[i]] = i;
            }
        }
        
        int ans = 0;
        psum = 0;
        
        for (int i = 0 ; i < n ; i++) {
            psum += nums[i];
            
            if (lower <= psum and psum <= upper)
                ans++;
            
            // Some other prefix sum must lie between [psum - upper, psum - lower]
            // Count number of such prefixes

            long long int big = max(psum - lower, psum - upper - 1);
            long long int small = min(psum - lower, psum - upper - 1);
                        
            int indx = upper_bound(sums.begin(), sums.end(), big) - sums.begin() - 1;
            
            ans += query(indx);
            
            indx = upper_bound(sums.begin(), sums.end(), small) - sums.begin() - 1;
            
            if (indx >= 0)
                ans -= query(indx);
            
            update(position[psum], n, 1);
        }
        
       
        return ans;
    }
};