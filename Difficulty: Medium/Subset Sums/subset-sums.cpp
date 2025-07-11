class Solution {
  public:
    void genAll(int i,int sum,vector<int>&arr,vector<int>&ans){
        ans.push_back(sum);
        if(i>=arr.size())return;
        
        for(int j=i;j<arr.size();j++){
            sum+=arr[j];
            genAll(j+1,sum,arr,ans);
            sum-=arr[j];
        }
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int>ans;
        genAll(0,0,arr,ans);
        return ans;
    }
};