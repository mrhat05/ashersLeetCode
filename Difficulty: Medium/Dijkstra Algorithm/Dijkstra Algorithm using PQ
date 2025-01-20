// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
       int n=adj.size();
       vector<int>dis(n,INT_MAX);
       dis[src]=0;
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       pq.push({0,src});
       while(!pq.empty()){
           auto curr=pq.top();
           pq.pop();
           for(auto&it:adj[curr.second]){
               if(dis[it.first]>dis[curr.second]+it.second){
                   dis[it.first]=dis[curr.second]+it.second;
                   pq.push({dis[it.first],it.first});
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
