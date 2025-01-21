class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;

        if (m == 1 && n == 1) return grid[0][0] == 0 ? 1 : -1;

        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        dis[0][0] = 1;
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
        queue<pair<int, int>> q;
        q.push({0, 0});

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (auto& [dx, dy] : dir) {
                int nx = x + dx, ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 0 && dis[x][y] + 1 < dis[nx][ny]) {
                    dis[nx][ny] = dis[x][y] + 1;

                    if (nx == m - 1 && ny == n - 1) return dis[nx][ny];

                    q.push({nx, ny});
                }
            }
        }

        return -1;
    }
};
