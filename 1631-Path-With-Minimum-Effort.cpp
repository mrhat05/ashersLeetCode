class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>dis(m,vector<int>(n,INT_MAX));
        dis[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int x=it.second.first;
            int y=it.second.second;

            if(x==m-1 && y==n-1)return diff;

            for(auto& [dx, dy] : dir){
                int nx=x+dx,ny=y+dy;
                if(nx >= 0 && ny >= 0 && nx < m && ny < n ){
                    int max_diff=max(abs(heights[x][y]-heights[nx][ny]),diff);

                    if(max_diff<dis[nx][ny]){
                        dis[nx][ny]=max_diff;
                        pq.push({max_diff,{nx,ny}});
                    }

                    
                }
            }
        }
        return 0;

    }
};