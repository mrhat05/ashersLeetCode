class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<pair<int, int>> dir = {{0,1}, {0,-1}, {-1,0}, {1,0}};
        
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        int result = 0;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int t = curr[0], x = curr[1], y = curr[2];
            result = max(result, t);

            if (x == n-1 && y == n-1) return result; 

            for (auto& d : dir) {
                int nx = x + d.first, ny = y + d.second;
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    pq.push({grid[nx][ny], nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }

        return -1;
    }
};
