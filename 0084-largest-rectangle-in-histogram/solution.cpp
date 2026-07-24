class Solution {
public:
    vector<int> getPREVS(vector<int>& heights , int n){
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> getNEXTS(vector<int>& heights , int n){
        vector<int> ans(n,n);
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prevS = getPREVS(heights,n);
        vector<int> nextS = getNEXTS(heights,n);
        int ans = 0;

        for(int i = 0;i<n;i++){
            ans = max(ans,((nextS[i] - prevS[i] -1)*heights[i]));
        }
        return ans;
    }
};
