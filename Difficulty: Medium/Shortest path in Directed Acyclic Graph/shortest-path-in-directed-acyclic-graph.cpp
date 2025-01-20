//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(V);
        for(auto&it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dis(V,INT_MAX);
        queue<int>q;
        q.push(0);
        dis[0]=0;
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto&it:adj[curr]){
                if(dis[it.first]>dis[curr]+it.second){
                    dis[it.first]=dis[curr]+it.second;
                    q.push(it.first);
                }
            }
        }
        vector<int>ans(V,-1);
        for(int i=0;i<V;i++){
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends