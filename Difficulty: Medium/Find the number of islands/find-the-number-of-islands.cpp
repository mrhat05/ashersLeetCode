//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  private:
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& grid,int m,int n){
        if(i>m-1 || j>n-1 ||i<0 || j<0 || vis[i][j])return;
        
        vis[i][j]=1;
        
        vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        
        for(auto&it:dir){
            int nx=i+it.first,ny=j+it.second;
            if(nx<m && ny<n && nx>=0 && ny>=0 &&grid[nx][ny]=='1' && !vis[nx][ny])
                dfs(nx,ny,vis,grid,m,n);
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,vis,grid,m,n);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends