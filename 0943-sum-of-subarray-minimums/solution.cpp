class Solution {
public:
    vector<int> getPSE(vector<int>& arr, int n) {
        vector<int> pse(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }

    vector<int> getNSE(vector<int>& arr, int n) {
        vector<int> nse(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--){
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse = getPSE(arr, n);
        vector<int> nse = getNSE(arr, n);
        const long long MOD = 1e9 + 7;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            ans = (ans + (left * right)%MOD * arr[i]) % MOD;
        }
        return (int)ans;
    }
};
