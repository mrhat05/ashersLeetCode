class Solution {
public:
    string removeOccurrences(string s, string part) {
        char backC=part.back();
        int partLen=part.size();
        string res="";
        for(auto&it:s){
            res.push_back(it);
            if(res.size()>=partLen && res.back()==backC){
                if(res.substr(res.size()-partLen)==part){
                    res.erase(res.size()-partLen,partLen);
                }
            }
        }
        return res;
    }
};