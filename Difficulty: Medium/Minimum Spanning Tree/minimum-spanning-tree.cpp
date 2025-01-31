//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet{
    vector<int>par,siz;
    public:
        DisjointSet(int n){
            par.resize(n+1);
            siz.resize(n+1,0);
            
            for(int i=0;i<=n;i++){
                par[i]=i;
                siz[i]=1;
            }
        }
        
        int findUlP(int x){
            if(par[x]==x)return x;
            
            return par[x]=findUlP(par[x]);
        }
        
        void unionSiz(int x,int y){
            int ulP_x=findUlP(x);
            int ulP_y=findUlP(y);
            
            if(ulP_x==ulP_y)return;
            
            if(siz[ulP_x]<siz[ulP_y]){
                par[ulP_x]=ulP_y;
                siz[ulP_y]+=siz[ulP_x];
            }
            else{
                par[ulP_y]=ulP_x;
                siz[ulP_x]+=siz[ulP_y];
            }
        }
};
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
       vector<vector<int>>edges;
       for(int i=0;i<V;i++){
           for(auto&it:adj[i]){
               int node=i;
               int childNode=it[0];
               int childWt=it[1];
               
               edges.push_back({childWt,node,childNode});
           }
       }
       sort(edges.begin(),edges.end());
       DisjointSet ds(V);
       int ansWt=0;
       for(auto&it:edges){
           int u=it[1];
           int v=it[2];
           int wt=it[0];
           
           if(ds.findUlP(u)!=ds.findUlP(v)){
               ansWt+=wt;
               ds.unionSiz(u, v); 
           }
       }
       
       return ansWt;
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