class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> indegree(n, 0);
        vector<vector<int>> adjRev(n);

        for (int i = 0; i < n; i++) {
            for (auto& it : adj[i]) {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for (auto& it : adjRev[curr]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
