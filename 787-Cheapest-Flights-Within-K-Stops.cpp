class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto&it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dis(n,INT_MAX);
        dis[src]=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,src});

        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();

            if(curr[0]>k)continue;

            for(auto&it:adj[curr[2]]){
                if(dis[it.first]>curr[1]+it.second && curr[0]<=k){
                    dis[it.first]=curr[1]+it.second;
                    pq.push({curr[0]+1,dis[it.first],it.first});
                }
            }
        }
        return dis[dst]==INT_MAX ?-1 :dis[dst];
    }
};