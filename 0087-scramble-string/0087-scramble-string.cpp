class Solution {
public:
    unordered_map<string, bool> mp;

    bool solve(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.size() != s2.size()) return false;

        string key = s1 + "#" + s2;
        if (mp.count(key)) return mp[key];

        string a = s1, b = s2;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a != b) return mp[key] = false;

        int n = s1.size();
        for (int i = 1; i < n; i++) {
            if ((solve(s1.substr(0, i), s2.substr(0, i)) &&
                 solve(s1.substr(i), s2.substr(i))) ||
                (solve(s1.substr(0, i), s2.substr(n - i)) &&
                 solve(s1.substr(i), s2.substr(0, n - i)))) {
                return mp[key] = true;
            }
        }

        return mp[key] = false;
    }

    bool isScramble(string s1, string s2) {
        mp.clear();
        return solve(s1, s2);
    }
};