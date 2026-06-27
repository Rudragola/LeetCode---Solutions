class Solution {
public:

    bool isPossible(vector<int>& weights , int days , int mid){
        int curSum = 0;
        int ans = 1;
        for(int it : weights){
            if(curSum + it <= mid){
                curSum += it;
            }else{
                curSum = it;
                ans++;
            }
        }
        return (ans <= days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low  = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = 0;
        while(low <= high){
            int mid = low + (high-low) / 2;

            if(isPossible(weights , days , mid)){
                ans = mid ;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
