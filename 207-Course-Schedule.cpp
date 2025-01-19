class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        for(auto&it:prerequisites){
            int x=it[0];
            int y=it[1];
            adj[y].push_back(x);
        }

        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }

        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0)q.push(i);
        }
        
        vector<int>ans;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(auto&it:adj[curr]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }

        return (ans.size()==n);

    }
};