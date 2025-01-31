class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int>vis(V,0);

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        
        pq.push({0,0,-1});
        
        int sum=0;
        
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            
            int node=it[1];
            int srcNode=it[2];
            int wt=it[0];
            
            if(vis[node]!=1){
                vis[node]=1;
                sum+=wt;
                for(auto&it:adj[node]){
                    int childNode=it[0];
                    int childWt=it[1];
                    if(vis[childNode]!=1){
                        pq.push({childWt,childNode,node});
                    }
                }
            }
        }
        return sum;
    }
};
