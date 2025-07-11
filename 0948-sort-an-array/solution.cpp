class Solution {
public:
    void merge(vector<int>& arr, int str, int mid, int end) {
        vector<int> temp;
        int i = str, j = mid + 1;

        while (i <= mid && j <= end) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
            }
        }
        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }
        while (j <= end) {
            temp.push_back(arr[j]);
            j++;
        }
        for (int idx = 0; idx < temp.size(); idx++) {
            arr[idx+str] = temp[idx];
        }
    }

    void mergeSort(vector<int>& arr, int str, int end) {
        if (str < end) {
            int mid = str + (end - str) / 2;

            // left part
            mergeSort(arr, str, mid);

            // right part
            mergeSort(arr, mid + 1, end);

            // merge sorted array
            merge(arr, str, mid, end);
        }
    }
    vector<int> sortArray(vector<int>& nums) {

        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};
