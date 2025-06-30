class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(2,0);
        unordered_map<int,int>mp;
        for(auto&it:arr){
                mp[it]++;
                if(mp[it]==2)ans[0]=it;
        }

        for(int i=1;i<=n;i++){
            if(mp.find(i)==mp.end()){
                ans[1]=i;
                break;
            }
        }

        return ans;
    }
};