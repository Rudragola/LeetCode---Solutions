class Solution {
public:

    vector<vector<int>> answer = {};
    vector<int> currentSeq = {};

    void recursion(vector<int>& nums , int index){

        //base case
        if(index == nums.size()){
            answer.push_back(currentSeq);
            return;
        }

        //option 1 -> to choose the element 
        currentSeq.push_back(nums[index]);
        recursion(nums , index+1);
        currentSeq.pop_back();

        //option2 -> to not to choose the element
        recursion(nums, index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        recursion(nums , 0);
        return answer;
    }
};
