// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int N) {
        vector<int>coins={1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        
        int sum=N;
        int i=coins.size()-1;
        
        vector<int>ans;
        
        while(i>=0 && sum>0){
            int coinsCanAllocate=sum/coins[i];
            
            if(coinsCanAllocate==0){
                i--;
                continue;
            }
            
            sum-=coinsCanAllocate*coins[i];
            while(coinsCanAllocate--)ans.push_back(coins[i]);
        }
        
        return ans;
    }
};