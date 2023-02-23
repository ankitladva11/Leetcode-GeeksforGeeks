class Solution {
public:
    int findMaximizedCapital(int k, int res, vector<int> &ps, vector<int> &cs) {
        // support variables
        int len = ps.size(), sorted[len], r = 0;
        priority_queue<int> pqProfits;
        // preparing sorted, sorting by increasing capital
        iota(sorted, sorted + len, 0);
        sort(sorted, sorted + len, [&cs](int a, int b){
            return cs[a] < cs[b];
        });
        // getting the k most convenient investments
        while (k--) {
            // filling qProfits
            while (r < len && cs[sorted[r]] <= res) pqProfits.push(ps[sorted[r++]]);
            // no more options, we quit
            if (!pqProfits.size()) break;
            // adding the next best profit in
            res += pqProfits.top(), pqProfits.pop();
        }
        return res;
    }
};