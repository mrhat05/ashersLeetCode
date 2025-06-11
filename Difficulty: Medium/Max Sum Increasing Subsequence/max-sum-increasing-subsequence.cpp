class Solution {
  public:
    int solve(int i,int prev,int n,vector<int>&arr,vector<vector<int>>&dp){
        if(i>=n)return 0;
        
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        
        int notPick=solve(i+1,prev,n,arr,dp);
        
        int pick=INT_MIN;
        if(prev==-1 || arr[i]>arr[prev]){
            pick=arr[i]+solve(i+1,i,n,arr,dp);
        }
        
        return dp[i][prev+1]=max(pick,notPick);
    }
    
    int maxSumIS(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        return solve(0,-1,n,arr,dp);
    }
};