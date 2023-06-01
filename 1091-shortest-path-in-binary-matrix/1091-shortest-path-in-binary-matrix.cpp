class Solution {
public:
    int bfs(vector<vector<int>>& grid, vector<vector<int>>&vis){
       int n=grid.size();
        vis[0][0]=1;
        int dr[8]={1,-1,0,0,1,-1,1,-1};
        int dc[8]={0,0,1,-1,1,-1,-1,1};
        queue<pair<int,int>>q;
        q.push({0,0});
        int step=0;
        while(!q.empty()){
            int size=q.size();
            step++;
            for(int i=0;i<size;i++){
                 int r=q.front().first;
                 int c=q.front().second;
                  q.pop();
                  if(r==n-1 && c==n-1){
                       return step;
                         break;
                   }
                for(int k=0;k<8;k++){
                 int nr=r+dr[k];
                 int nc=c+dc[k];
                 if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==0 ){
                     vis[nr][nc]=1;
                     q.push({nr,nc});
                 }

                }

           }
    }
    return -1;
}
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1 )return -1;
         int n=grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        return bfs(grid,vis);
    }
};