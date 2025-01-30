//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
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

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends