class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if(right<2)return {-1,-1};
        vector<bool>prime(right+1,true);
        prime[0]=false;
        prime[1]=false;

        for(int i=2;i*i<=right;i++){
            if(prime[i]==true){
                for(int j=i*i;j<=right;j+=i){
                    prime[j]=false;
                }
            }
        }
        vector<int>temp;
        for(int i=left;i<=right;i++){
            if(prime[i])temp.push_back(i);
        }
        if(temp.size()<2)return {-1,-1};
        int mini=INT_MAX;
        int a=-1,b=-1;
        for(int i=0;i<temp.size()-1;i++){
            int curr=abs(temp[i+1]-temp[i]);
            if(mini>curr){
                mini=curr;
                a=temp[i];
                b=temp[i+1];
            }
        }
        return {a,b};
    }
};