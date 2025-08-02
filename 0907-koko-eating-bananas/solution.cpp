class Solution {
public:
    bool canEatAll(vector<int>& piles, int mid, int h){
        int timeTaken = 0;

        for(int& numOfBananas: piles){
            timeTaken += numOfBananas/mid;
            if(numOfBananas%mid != 0){
                timeTaken++;
            }
        }

        return timeTaken<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        while(low < high){
            int mid = low + (high-low)/2;

            if(canEatAll(piles, mid, h)){
                high = mid;
            }else{
                low = mid + 1;
            }
        }

        return low;
    }
};
