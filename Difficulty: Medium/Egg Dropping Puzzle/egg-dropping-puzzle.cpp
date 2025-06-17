class Solution {
  public:
    int eggDrop(int n, int k) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,INT_MAX));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
            dp[i][1]=1;
        }
        for(int i=0;i<=k;i++){
            dp[1][i]=i;
        }
        
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= k; j++) {
                int low = 1, high = j, res = INT_MAX;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    int breaks = dp[i - 1][mid - 1];   
                    int notBreaks = dp[i][j - mid];
                    int worst = 1 + max(breaks, notBreaks);
                    if (breaks < notBreaks) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                    res = min(res, worst);
                }
                dp[i][j] = res;
            }
            
        }
        
        return dp[n][k];
    }
};