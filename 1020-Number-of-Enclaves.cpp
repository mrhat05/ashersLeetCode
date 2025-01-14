class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int m,int n,int& cnt){
        if(i<0 || j<0 || i>m-1 || j>n-1 || grid[i][j]!=1 ||vis[i][j])return;

        cnt++;
        vis[i][j]=1;

        dfs(i+1,j,grid,vis,m,n,cnt);
        dfs(i-1,j,grid,vis,m,n,cnt);
        dfs(i,j+1,grid,vis,m,n,cnt);
        dfs(i,j-1,grid,vis,m,n,cnt);

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int total=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)total++;
            }
        }
        int cnt=0;
        for(int j=0;j<n;j++){
            if(grid[0][j]==1)dfs(0,j,grid,vis,m,n,cnt);
            if(grid[m-1][j]==1)dfs(m-1,j,grid,vis,m,n,cnt);
        }

        for(int i=0;i<m;i++){
            if(grid[i][0]==1)dfs(i,0,grid,vis,m,n,cnt);
            if(grid[i][n-1]==1)dfs(i,n-1,grid,vis,m,n,cnt);
        }
        
        cout<<total<<" "<<cnt;
        return total-cnt;
    }
};