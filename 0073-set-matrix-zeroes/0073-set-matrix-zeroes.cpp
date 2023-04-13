class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> indexes;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == 0) indexes.push_back({i,j});
            }
        }
        
        if(indexes.size() == 0) return;

        int n2 = indexes.size();
        for(int i=0; i<n2; i++) {
            int row = indexes[i][0];
            int col = indexes[i][1];

            for(int p=0; p<m; p++) matrix[row][p] = 0;
            for(int p=0; p<n; p++) matrix[p][col] = 0;
        }
    }
};