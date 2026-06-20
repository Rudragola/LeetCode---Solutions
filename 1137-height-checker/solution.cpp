class Solution {
public:
    int heightChecker(vector<int>& heights) {
       vector<int> sortt = heights;
       sort(sortt.begin() , sortt.end());
       int count = 0;


       for(int i= 0;i<heights.size();i++){
            if(sortt[i] != heights[i]){
                count++;
            }
       }
       return count;

    }
};
