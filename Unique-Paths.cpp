class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i<0 || j<0 || i>m-1 || j>n-1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==m-1 && j==n-1)return 1;

        return dp[i][j]=solve(i+1,j,m,n,dp)+solve(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,dp);
    }
};