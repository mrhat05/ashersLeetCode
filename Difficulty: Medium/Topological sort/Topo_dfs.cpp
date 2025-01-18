class Solution {
  private:
    void dfs(int i,vector<vector<int>>&adj,vector<int>&vis,stack<int>&st){
        vis[i]=1;
        for(auto&it:adj[i]){
            if(!vis[it]){
                dfs(it,adj,vis,st);
            }
        }
        st.push(i);
    }
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>vis(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
