class Solution {
  public:
    int nthRoot(int n, int m) {
        int low=0,high=m;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            long long powered=pow(mid,n);
            
            if(powered==m)return mid;
            else if(powered<m)low=mid+1;
            else high=mid-1;
        }
        
        return -1;
    }
};