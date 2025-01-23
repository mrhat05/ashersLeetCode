//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        if(start==end)return 0;
        queue<pair<int,int>>pq;
        
        vector<int>vis(100000,0);
        vis[start]=1;
        pq.push({0,start});
        
        while(!pq.empty()){
            auto curr=pq.front();
            pq.pop();
            int steps=curr.first;
            int val=curr.second;
            
            for(auto&it:arr){
                long long mul=val*it;
                int mulMod=mul%100000;
                
                if(mulMod==end)return steps+1;
                if(!vis[mulMod]){
                    vis[mulMod]=1;
                    pq.push({steps+1,mulMod});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends