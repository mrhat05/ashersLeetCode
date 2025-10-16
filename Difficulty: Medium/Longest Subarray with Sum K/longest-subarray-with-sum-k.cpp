class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int maxLen=0;
        int endInd=-1;
        int sum=0;
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            
            if(sum==k){
                maxLen=i+1;
                endInd=i;
            }
            else if(mp.find(sum-k)!=mp.end()){
                maxLen=max(maxLen,i-mp[sum-k]);
                endInd=i;
            }
            
            if (mp.find(sum) == mp.end()) mp[sum] = i;

        }
        
        return maxLen;
    }
};