class Solution {
public:
    unordered_map<string, vector<string>> adj;
    unordered_map<string, int> dist;
    vector<vector<string>> res;

    void dfs(string &word, string &beginWord, vector<string> &path) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            res.push_back(temp);
            return;
        }

        for (string &prev : adj[word]) {
            if (dist[prev] + 1 == dist[word]) {
                path.push_back(prev);
                dfs(prev, beginWord, path);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (!st.count(endWord)) return {};

        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 0;

        while (!q.empty()) {
            string w = q.front(); q.pop();

            string temp = w;
            for (int i = 0; i < temp.size(); i++) {
                char orig = temp[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (st.count(temp)) {
                        if (!dist.count(temp)) {
                            dist[temp] = dist[w] + 1;
                            q.push(temp);
                        }
                        if (dist[temp] == dist[w] + 1) {
                            adj[temp].push_back(w);
                        }
                    }
                }
                temp[i] = orig;
            }
        }

        if (!dist.count(endWord)) return {};

        vector<string> path;
        path.push_back(endWord);
        dfs(endWord, beginWord, path);

        return res;
    }
};