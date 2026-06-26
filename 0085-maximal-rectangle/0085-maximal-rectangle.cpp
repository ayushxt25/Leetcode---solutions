class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int n = matrix[0].size();
        vector<int> height(n, 0);
        int ans = 0;

        for (auto &row : matrix) {
            for (int j = 0; j < n; j++) {
                height[j] = (row[j] == '1') ? height[j] + 1 : 0;
            }

            stack<int> st;
            for (int j = 0; j <= n; j++) {
                int cur = (j == n ? 0 : height[j]);

                while (!st.empty() && cur < height[st.top()]) {
                    int h = height[st.top()];
                    st.pop();
                    int l = st.empty() ? -1 : st.top();
                    ans = max(ans, h * (j - l - 1));
                }
                st.push(j);
            }
        }

        return ans;
    }
};