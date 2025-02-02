class DisjointSet{
    vector<int>siz,par;
    public:
        DisjointSet(int n){
            par.resize(n+1);
            siz.resize(n+1,0);
            for(int i=0;i<=n;i++){
                par[i]=i;
                siz[i]=1;
            }
        }

        int findUlP(int x){
            if(x==par[x])return x;

            return par[x]=findUlP(par[x]);
        }

        void unionBySiz(int x,int y){
            int ulP_x=findUlP(x);
            int ulP_y=findUlP(y);

            if(ulP_x==ulP_y)return;

            if(siz[ulP_x]<siz[ulP_y]){
                par[ulP_x]=ulP_y;
                siz[ulP_y]+=siz[ulP_x];
            }
            else{
                par[ulP_y]=ulP_x;
                siz[ulP_x]+=siz[ulP_y];
            }
        }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=0;
        int maxcol=0;
        for(auto&it:stones){
            maxrow=max(it[0],maxrow);
            maxcol=max(it[1],maxcol);
        }

        DisjointSet ds(maxrow+maxcol+1);
        unordered_map<int,int>mp;
        for(auto&it:stones){
            int row=it[0];
            int col=it[1]+maxrow+1;
            ds.unionBySiz(row,col);
            mp[row]=1;
            mp[col]=1;
        }

        int cnt=0;
        for(auto&it:mp){
            if(ds.findUlP(it.first)==it.first)cnt++;
        }

        return n-cnt;
    }
};