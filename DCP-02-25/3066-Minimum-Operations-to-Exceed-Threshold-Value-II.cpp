class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(auto& it : nums) {
            pq.push(it);
        }
        int cnt = 0;
        while (!pq.empty()) {
            long long curr1 = pq.top(); 
            pq.pop();

            if (curr1 >= k) return cnt;
            
            if (pq.empty()) break;
            cnt++;
            long long curr2 = pq.top();
            pq.pop();
            pq.push(curr1 * 2 + curr2);
        }
        return cnt;
    }
};
