class Solution {
public:
    void reverse(vector<int>& nums,int st , int end){
        while(st<end){
            swap(nums[st] , nums[end]);
            st++;
            end--;
        }
        
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k=k%n;
        
        //reverse array 
        reverse(nums , 0 , n-1);

        //reverse upto k
        reverse(nums , 0 , k-1);

        //reverse after k
        reverse(nums , k ,n-1);
    }
};
