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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cnt1=0;
        DisjointSet ds(n);
        for(auto&it:connections){
            int u=it[0];
            int v=it[1];

            if(ds.findUlP(u)==ds.findUlP(v)){
                cnt1++;
            }else{
                ds.unionBySiz(u,v);
            }
        }
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(ds.findUlP(i)==i)cnt2++;
        }
        
        if(cnt1>=cnt2-1)return cnt2-1;

        return -1;
    }
};