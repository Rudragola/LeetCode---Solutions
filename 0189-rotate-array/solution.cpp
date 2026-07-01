class Solution {
public:

    void reverse(vector<int>& nums , int n , int m){
        int i = n;
        int j = m;
        while(i <j){
            swap(nums[i] , nums[j]);
            i++;
            j--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
         if(k == 0) return;
         k = k%n;
        k = n-k;
        //reverse first k
        reverse(nums , 0 , k - 1);

        //reverse after k
        reverse(nums ,k , n-1);

        //reverse whole array
        reverse(nums , 0 , n-1);
    }
};
