class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(auto&it:dir){
                auto [dx,dy]=it;
                int nx=x+dx,ny=y+dy;
                if(nx>=0 && ny>=0 && 
                nx<m && ny<n && ans[nx][ny]>ans[x][y]+1){
                    ans[nx][ny]=ans[x][y]+1;
                    q.push({nx,ny});            
                }
            }
        }
        return ans;
    }
};