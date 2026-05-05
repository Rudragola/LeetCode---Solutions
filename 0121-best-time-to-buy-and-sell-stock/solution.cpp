class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof = 0;
        int maxProf = -1;
        int buy = prices[0];
        int n = prices.size();

        for(int i = 0;i<n;i++){
            if(buy > prices[i]){
                buy = prices[i];
            }
            else{
                prof = prices[i] - buy;
            }
            if(maxProf < prof){
                maxProf = prof;
            }
        }
        return maxProf;
    }
};
