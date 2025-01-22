class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD=1e9+7;
        vector<vector<pair<int,int>>>adj(n);
        for(auto&it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>dis(n,LLONG_MAX);
        vector<int>ways(n,0);
        dis[0]=0;
        ways[0]=1;

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});

        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            long long time=curr.first;
            int node=curr.second;

            for(auto&it:adj[node]){
                long long nextNode=it.first;
                long long nextTime=it.second;
                long long newDist = time + nextTime;
                if(dis[nextNode]>newDist){
                    dis[nextNode]=newDist;
                    ways[nextNode]=ways[node];
                    pq.push({dis[nextNode],nextNode});
                }
                else if (dis[nextNode] == 
                newDist) {
                    ways[nextNode] = 
                    (ways[nextNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1]%MOD;
    }
};