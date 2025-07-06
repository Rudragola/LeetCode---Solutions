class Solution {
public:

    vector<vector<int>> ans = {};
    vector<int> currentSeq = {};
    void recursion(vector<int>& candidates , int target , int start){

        if(target == 0){
            ans.push_back(currentSeq);
            return;
        }

        for(int i = start;i<candidates.size();i++){
            if(target >= candidates[i]){
                currentSeq.push_back(candidates[i]);
                recursion(candidates , target - candidates[i] , i);
                currentSeq.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        recursion(candidates,target,0);
        return ans;
    }
};



