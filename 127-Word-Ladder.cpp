class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        for(auto&it:wordList){
            st.insert(it);
        }
        if(!st.count(endWord))return 0;

        queue<string>q;
        q.push(beginWord);
        int ladder=1;

        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                string word=q.front();
                q.pop();
                for(int j=0;j<word.size();j++){
                    string nextWord=word;
                    for(char k='a';k<='z';k++){
                        nextWord[j]=k;

                        if(nextWord==endWord)return ladder+1;

                        if(st.count(nextWord)){
                            q.push(nextWord);
                            st.erase(nextWord);
                        }
                    }
                }
            }
            ladder++;
        }
        return 0;
    }
};