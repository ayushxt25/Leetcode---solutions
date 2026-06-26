class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> count(128, 0);

        for(char ch : t){
            count[ch]++;
        }

        int left = 0;
        int minStart = 0;
        int minlen = INT_MAX;
        int need = t.size();

        for(int right = 0; right < s.size(); right++){
            if(count[s[right]] > 0){
                need--;
            }
            count[s[right]]--;

            while(need == 0){
                if(right - left + 1 < minlen){
                    minlen = right - left + 1;
                    minStart = left;
                }
                count[s[left]]++;

                if(count[s[left]] > 0){
                    need++;
                }
                left++;
            }
        }
        return minlen == INT_MAX ? "" : s.substr(minStart, minlen);
    }
};