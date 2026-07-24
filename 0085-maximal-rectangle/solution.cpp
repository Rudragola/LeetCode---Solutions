class Solution {
public:
    vector<int> getPREVS(vector<int>& heights, int n) {
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> getNEXTS(vector<int>& heights, int n) {
        vector<int> ans(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights, int m) {
        vector<int> prevS = getPREVS(heights, m);
        vector<int> nextS = getNEXTS(heights, m);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            ans = max(ans, ((nextS[i] - prevS[i] - 1) * heights[i]));
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> psum(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += matrix[j][i] - '0';
                if (matrix[j][i] == '0') {
                    sum = 0;
                }
                psum[j][i] = sum;
            }
        }

        for (int i = 0; i < n; i++) {
            ans = max(ans, largestRectangleArea(psum[i], m));
        }
        return ans;
    }
};
