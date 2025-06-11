class Solution {
  public:
    int solve(int ind,int w,vector<int> &val, vector<int> &wt,vector<vector<int>>&dp){
        if(w==0 || ind<0)return 0;
        
        if(dp[ind][w]!=-1)return dp[ind][w];
        
        int notPicked = solve(ind-1,w,val,wt,dp);
        
        int picked=INT_MIN;
        
        if(wt[ind]<=w){
            picked=val[ind]+solve(ind-1,w-wt[ind],val,wt,dp);
        }
        
        return dp[ind][w]=max(picked,notPicked);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        
        return solve(n-1,W,val,wt,dp);
        
    }
};