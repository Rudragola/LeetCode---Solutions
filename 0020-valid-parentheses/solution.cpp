class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty())
                    return false;
                char cur = st.top();
                st.pop();
                if (s[i] == ')' && cur == '(' || s[i] == '}' && cur == '{' ||
                    s[i] == ']' && cur == '[')
                    continue;
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
