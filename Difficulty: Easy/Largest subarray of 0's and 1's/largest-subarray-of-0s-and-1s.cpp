class Solution {
  public:
    int maxLen(vector<int> &arr) {
        for(auto&it:arr){
            if(it==0)it=-1;
        }
        
        int maxLen=0;
        int endInd=-1;
        int sum=0;
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            
            if(sum==0){
                maxLen=i+1;
                endInd=i;
            }
            else if(mp.find(sum)!=mp.end()){
                maxLen=max(maxLen,i-mp[sum]);
                endInd=i;
            }
            else mp[sum]=i;
        }
        
        return maxLen;
    }
};