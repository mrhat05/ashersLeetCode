class Solution {
  public:
    bool canPlace(vector<int> &stalls, int k,int mid){
        int prev=stalls[0];
        int cnt=1;
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-prev>=mid){
                cnt++;
                prev=stalls[i];
            }
            if(cnt>=k)return true;
        }
        return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int low=1;
        int high=*max_element(stalls.begin(),stalls.end())-*min_element(stalls.begin(),stalls.end());
        
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(canPlace(stalls,k,mid)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};