class Disjointset{
    public:
    vector<int>siz,par;
        Disjointset(int n){
            siz.resize(n+1);
            par.resize(n+1,0);
            for(int i=0;i<=n;i++){
                par[i]=i;
                siz[i]=1;
            }
        }

        int findULP(int x){
            if(x==par[x])return x;

            return par[x]=findULP(par[x]);
        }

        void unionBySiz(int x,int y){
            int ULPx=findULP(x);
            int ULPy=findULP(y);

            if(ULPx==ULPy)return;

            if(siz[ULPx]<siz[ULPy]){
                par[ULPx]=ULPy;
                siz[ULPy]+=siz[ULPx];
            }
            else{
                par[ULPy]=ULPx;
                siz[ULPx]+=siz[ULPy];
            }
        }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        Disjointset ds(m*n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)continue;
                vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
                int node=i*m+j;
                for(auto& it:dir){
                    int nx=i+it.first;
                    int ny=j+it.second;
                    if(nx>=0 && ny>=0 && nx<m && ny <n && grid[nx][ny]==1){
                        int adjNode=nx*m+ny;
                        ds.unionBySiz(node,adjNode);
                    }
                }
            }
        }


        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)continue;
                vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
                int node=i*m+j;
                set<int>st;
                for(auto& it:dir){
                    int nx=i+it.first;
                    int ny=j+it.second;
                    if(nx>=0 && ny>=0 && nx<m && ny <n && grid[nx][ny]==1){
                        int adjNode=nx*m+ny;
                        st.insert(ds.findULP(adjNode));
                    }
                }
                int totalSiz=0;
                for(auto&it:st){
                    totalSiz+=ds.siz[it];
                }
                maxi=max(maxi,totalSiz+1);
            }
        }
        for(int i=0;i<m*n;i++){
            maxi=max(ds.siz[i],maxi);
        }
        return maxi;

    }
};