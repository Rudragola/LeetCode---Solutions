class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        /* map<int,int> mpp;
        int n = nums.size();
        vector<int> ans;
        

        for(int i= 0;i<n;i++){
            mpp[nums[i]]++;
        }

        for(auto& it : mpp){
            if(it.second > (n/3)){
                ans.push_back(it.first);
            }
        }
        return ans; */

        vector<int> ans;
        int count1 = 0,count2 = 0;
        int n = nums.size();
        int ele1 = INT_MIN , ele2 = INT_MIN;

        for(int i =0;i<n;i++){
            if(count1 == 0 && nums[i] != ele2){
                count1++;
                ele1 = nums[i];
            }else if( count2 == 0 && nums[i] != ele1){
                count2++;
                ele2 = nums[i];
            }else if(nums[i] == ele1){
                count1++;
            }else if(nums[i] == ele2){
                count2++;
            }else{
                count1--;
                count2--;
            }
        }

        //verification
        count1 = 0;
        count2 = 0;
        for(int i =0;i<n;i++){
            if(ele1 == nums[i]) count1++;
            else if(ele2 == nums[i]) count2++;
        }

        if(count1> (n/3)) ans.push_back(ele1);
        if(count2> (n/3)) ans.push_back(ele2);
        return ans;

    }
};
