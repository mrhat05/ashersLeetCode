class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& mat,int m,int n){
        if(i<0 || j<0 ||i>m-1 || j>n-1 || mat[i][j]!='O')return;

        mat[i][j]='#';

        dfs(i+1,j,mat,m,n);
        dfs(i-1,j,mat,m,n);
        dfs(i,j+1,mat,m,n);
        dfs(i,j-1,mat,m,n);
    }
    void solve(vector<vector<char>>& mat) {
        int m=mat.size();
        if (m == 0) return;
        int n=mat[0].size();        
        for(int j=0;j<n;j++){
            if(mat[0][j]=='O')dfs(0,j,mat,m,n);
            if(mat[m-1][j]=='O')dfs(m-1,j,mat,m,n);
        }


        for(int i=0;i<m;i++){
            if(mat[i][0]=='O')dfs(i,0,mat,m,n);
            if(mat[i][n-1]=='O')dfs(i,n-1,mat,m,n);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]=='O')mat[i][j]='X';
                if(mat[i][j]=='#')mat[i][j]='O';
            }
        }

    }
};