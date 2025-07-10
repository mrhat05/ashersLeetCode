class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
       sort(arr.begin(), arr.end());
       sort(dep.begin(), dep.end());
       
       int n=arr.size();
       int maxi=0;
       int cnt=0;int i=0,j=0;
       
       while(i<n && j<n){
           if(arr[i]<=dep[j]){
               cnt++;
               i++;
           }else{
               cnt--;
               j++;
           }
           maxi=max(cnt,maxi);
       }
       
       return maxi;
        
    }
};
