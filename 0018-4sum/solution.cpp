class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        
        for(int i = 0; i < n - 3; i++){
            // Skip duplicate fixed elements
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            
            
            for(int j = i + 1; j < n - 2; j++){
                // Skip duplicate elements in second loop
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                
                int k = j + 1;
                int l = n - 1;
                
                while(k < l){
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    
                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        
                        // Skip duplicates in k (moving right)
                        while(k < l && nums[k] == nums[k+1]) k++;
                        // Skip duplicates in l (moving left)
                        while(k < l && nums[l] == nums[l-1]) l--;
                        
                        k++;
                        l--;
                    }
                    else if(sum > target){
                        l--;
                    }
                    else{
                        k++;
                    }
                }
            }
        }
        return ans;
    }
};
