class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};

    bool find(int i, int j,int n, int m, vector<vector<int>>& grid, vector<vector<int>>& vis){
        if(grid[i][j]==1) return true;

        vis[i][j]=1;
        bool ans=true;
        for(int k=0;k<4;k++){
            int newi=i+dx[k];
            int newj=j+dy[k];
            if(newi<0 or newj<0 or newi>=n or newj>=m) ans=false;
            else if(!vis[newi][newj])ans = (ans & find(newi,newj,n,m,grid,vis));
        }

        return ans;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 and vis[i][j]==0){
                    ans+=find(i,j, n, m,grid,vis);
                }
            }
        }
        return ans;
    }
};