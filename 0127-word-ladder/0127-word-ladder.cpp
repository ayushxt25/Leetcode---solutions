class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(!st.count(endWord)){
            return 0;
        }

        queue<string> q;
        q.push(beginWord);

        int level = 1;

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                string w = q.front();
                q.pop();

                if(w == endWord){
                    return level;
                }

                for(int i = 0; i < w.size(); i++){
                    char orig = w[i];
                    for(char c = 'a'; c <= 'z'; c++){
                        w[i] = c;
                        if(st.count(w)){
                            q.push(w);
                            st.erase(w);
                        }
                    }
                    w[i] = orig;
                }
            }
            level++;
        }

        return 0;

    }
};