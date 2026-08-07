class Solution {
public:
    bool isPossible(int mid, vector<int>& piles, int h){
        long long ans = 0;
        int n = piles.size();
        for(int i = 0;i<n;i++){
           ans+=  ceil((double)piles[i] / (double)mid);
        }
        return (ans <= h);
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        long long ans = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isPossible(mid , piles , h)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid+1;
            }
        }
        return ans;
        


    }
};
