class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int sum=0;
        int cnt=0;
        unordered_map<int,int>mp;
        
        for(int i=0;i<arr.size();i++){
            sum^=arr[i];
            
            if(sum==k)cnt++;
            
            if(mp.find(sum^k)!=mp.end())cnt+=mp[sum^k];
            
            mp[sum]++;
        }
        
        return cnt;
    }
};