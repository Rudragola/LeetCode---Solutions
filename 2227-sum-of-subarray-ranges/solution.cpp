class Solution {
public:
    vector<int> getPSE(vector<int>& nums , int n){
        vector<int> pse(n,-1);
        stack<int> st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }

            if(!st.empty()){
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }

    vector<int> getNSE(vector<int>& nums , int n){
        vector<int> nse(n,n);
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }

            if(!st.empty()){
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }

    long long subArrayMin(vector<int>& nums , int n){
        long long ans = 0;
        vector<int> pse = getPSE(nums, n);
        vector<int> nse = getNSE(nums, n);
        for(int i = 0;i<n;i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;
            ans += (left * right)*nums[i];
        }
        return ans;
    }

    vector<int> getPGE(vector<int>& nums , int n){
        vector<int> pge(n,-1);
        stack<int> st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }

            if(!st.empty()){
                pge[i] = st.top();
            }
            st.push(i);
        }
        return pge;
    }

    vector<int> getNGE(vector<int>& nums , int n){
        vector<int> nge(n,n);
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }

            if(!st.empty()){
                nge[i] = st.top();
            }
            st.push(i);
        }
        return nge;
    }

    long long subArrayMax(vector<int>& nums , int n){
        long long ans = 0;
        stack<int> st;
        vector<int> pge = getPGE(nums, n);
        vector<int> nge = getNGE(nums, n);
        for(int i = 0;i<n;i++){
            long long left = i - pge[i];
            long long right = nge[i] - i;
            ans += (left * right)*nums[i];
        }
        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        return subArrayMax(nums,n) - subArrayMin(nums,n);
    }
};
