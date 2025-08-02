class Solution {
  public:
    int findNo(vector<int>&arr,int mid){
        int students=1;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }else{
                students++;
                sum=arr[i];
            }
        }
        
        return students;
    }
    int findPages(vector<int> &arr, int k) {
     if(arr.size()<k)return -1;
        
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        
        int result = -1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(findNo(arr,mid)<=k){
                result=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        
        return result;
    }
};