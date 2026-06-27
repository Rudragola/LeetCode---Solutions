class Solution {
public:

    bool isPossible(vector<int>& day , int mid , int m , int k){
        int count  = 0;
        int ans = 0;

        for(int i = 0;i<day.size();i++){
            if(day[i]<=mid){
                count++;
            }else{
                ans += count/k;
                count = 0;
            }
        }
        ans += count/k;
        return (ans >= m);
    }

    int minDays(vector<int>& day, int m, int k) {

        if((1LL * m * k) > day.size()) return -1;
        int i = *min_element(day.begin(), day.end());
        int j = *max_element(day.begin(), day.end());
        int ans = 0;

        while(i<=j){
            int mid = (i+j) / 2;

            if(isPossible(day , mid , m ,k)){
                ans = mid;
                j = mid - 1;
            }else{
                i = mid + 1;
            }
        }
        return ans;
    }
};
