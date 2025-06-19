class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int i = 0;
        while(i<n){
            //fixing one element
            int target = -nums[i];

            //two sum
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[j] + nums[k];

                if(sum == target){
                    ans.push_back({nums[i] , nums[j] , nums[k]});

                    int currentI = nums[j];
                    while(j<n && currentI == nums[j]){
                        j++;
                    }

                    int currentk = nums[k];
                    while(k>=0 && currentk == nums[k]){
                        k--;
                    }
                }
                else if(sum>target){
                    k--;
                }else{
                    j++;
                }
            }

            int currentI = nums[i];
            while(i<n && currentI == nums[i]){
                i++;
            }

        }

        return ans;
    }
};
