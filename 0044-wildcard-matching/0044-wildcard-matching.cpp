class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        prev[0] = 1;

        for(int j = 1; j <= m; j++){
            if(p[j-1] == '*'){
                prev[j] = prev[j-1];
            }
        }

        for(int i = 1; i <= n; i++){
            curr[0] = 0;

            for(int j = 1; j <= m; j++){
                if(p[j - 1] == '*'){
                    curr[j] = curr[j-1] || prev[j];
                } else if (p[j-1] == '?' || p[j-1] == s[i-1]){
                    curr[j] = prev[j - 1];
                } else {
                    curr[j] = 0;
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};