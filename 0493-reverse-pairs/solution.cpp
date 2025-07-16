class Solution {
public:
    int merge(vector<int>& nums, int str, int mid, int end) {
        int i = str, j = mid + 1, reversePairs = 0;

        // Count reverse pairs
        for(i = str; i <= mid; i++) {
            while(j <= end && nums[i] > 2LL * nums[j]) {
                j++;
            }
            reversePairs += (j - (mid + 1));
        }

        // Merge step
        i = str;
        j = mid + 1;
        vector<int> temp;
        while(i <= mid && j <= end) {
            if(nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }
        while(i <= mid) temp.push_back(nums[i++]);
        while(j <= end) temp.push_back(nums[j++]);

        for(int k = 0; k < temp.size(); k++) {
            nums[str + k] = temp[k];
        }

        return reversePairs;
    }

    int mergeSort(vector<int>& nums, int str, int end) {
        if(str >= end) return 0;
        int mid = str + (end - str) / 2;
        int lrp = mergeSort(nums, str, mid);
        int rrp = mergeSort(nums, mid + 1, end);
        int rp = merge(nums, str, mid, end);
        return lrp + rrp + rp;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

