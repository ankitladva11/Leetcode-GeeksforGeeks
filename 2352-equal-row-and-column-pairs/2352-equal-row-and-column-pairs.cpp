class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count=0;
        vector<vector<int>>ans= grid;
        for(int i=0;i<grid.size();i++){
                    for(int j=0;j<grid.size();j++)
                    {
                        ans[i][j]=grid[j][i];
                    }
        }
         for(int i=0;i<grid.size();i++){
                    for(int j=0;j<grid.size();j++)
                    {
                        if(grid[i]==ans[j])
                            count+=1;
                    }
        }
        return count;
        
    }
};