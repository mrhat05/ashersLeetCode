class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,vector<string>>mp;
        for(auto&it:paths){
            string str1=it[0];
            string str2=it[1];
            mp[str1].push_back(str2);
            if(mp.find(str2)==mp.end()){
                mp[str2]={};
            }
        }

        for(auto&it:mp){
            if(it.second.empty()){
                return it.first;
            }
        }

        return "";

        
    }
};