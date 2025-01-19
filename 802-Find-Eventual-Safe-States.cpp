class Solution {
public:
    bool dfs(int i,vector<vector<int>>& graph,vector<int>&vis,vector<int>&pathVis){
        vis[i]=1;
        pathVis[i]=1;
        for(auto&it:graph[i]){
            if(!vis[it]){
                if(!dfs(it,graph,vis,pathVis))return false;
            }
            else if(pathVis[it]==1){
                return false;
            }
        }
        pathVis[i]=0;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>ans;
        vector<int>vis(n,0);
        vector<int>pathVis(n,0);
        for(int i=0;i<n;i++){
            if(dfs(i,graph,vis,pathVis))ans.push_back(i);
        }
        return ans;
    }
};