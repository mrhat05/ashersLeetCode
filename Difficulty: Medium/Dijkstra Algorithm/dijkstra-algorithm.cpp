//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
       int n=adj.size();
       vector<int>dis(n,INT_MAX);
       dis[src]=0;
       priority_queue<int,vector<int>,greater<int>>pq;
       pq.push(src);
       while(!pq.empty()){
           int curr=pq.top();
           pq.pop();
           for(auto&it:adj[curr]){
               if(dis[it.first]>dis[curr]+it.second){
                   dis[it.first]=dis[curr]+it.second;
                   pq.push(it.first);
               }
           }
       }
       vector<int>ans(n,-1);
       for(int i=0;i<dis.size();i++){
           if(dis[i]!=INT_MAX){
               ans[i]=dis[i];
           }
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends