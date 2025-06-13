class Solution {
public:
    void reverse(vector<int> &nums , int s , int e){
        while(s<e){
            int temp = nums[s];
            nums[s] = nums[e];
            nums[e] = temp;
            s++;
            e--;
        }
        
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k %n;

        //reverse entire array
        reverse(nums , 0 , n-1);

        //reverse first k elements
        reverse(nums , 0 , k-1);

        //reverse after k elements
        reverse(nums , k , n-1);
    }

};
