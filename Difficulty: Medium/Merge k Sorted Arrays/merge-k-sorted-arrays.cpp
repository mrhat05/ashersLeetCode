class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<int>ans;
        
        for(auto&it:arr){
            for(auto&it1:it){
                pq.push(it1);
            }
        }
        
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};