class Solution {
public:
    bool genall(int i,int sum,string&s,int num){
        if(i==s.size())return sum==num;

        for(int j=i;j<s.size();j++){
        int sub_num = stoi(s.substr(i, j - i + 1));        
        if(genall(j+1,sum+sub_num,s,num))return true;
        }

        return false;
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            string s=to_string(i*i);
            if(genall(0,0,s,i))ans+=i*i;
        }
        return ans;
    }
};