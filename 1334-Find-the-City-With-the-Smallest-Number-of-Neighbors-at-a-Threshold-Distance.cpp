class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>mat(n,vector<int>(n,-1));
        for(auto&it:edges){
            mat[it[0]][it[1]]=it[2];
            mat[it[1]][it[0]]=it[2];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == -1) {
                    mat[i][j] = 1e9;
                }
                if (i == j) mat[i][j] = 0;
            }
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }

        int cnt=INT_MAX;
        int ans=0;
        for (int i = 0; i < n; i++) {
            int curr_cnt=0;
            for (int j = 0; j < n; j++) {
                if(mat[i][j]<=distanceThreshold)curr_cnt++;
            }
            if(cnt>curr_cnt){
                cnt=curr_cnt;
                ans=i;
            }
            else if(cnt==curr_cnt){
                ans=max(ans,i);
            }
        }

        return ans;


    }
};