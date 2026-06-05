class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int cost;
        int mini = prices[0];
        int n = prices.size();

        for(int i = 1;i<n;i++){
            cost = prices[i] - mini;
            profit = max(profit , cost);
            mini = min(prices[i],mini);
        }
        return profit;
    }
};
