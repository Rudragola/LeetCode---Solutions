class Solution {
public:
    void recur(vector<string>& result, string curr, int n ,int open , int close) {
        if (curr.size() == n*2){
            result.push_back(curr);
        }
        if (open < n) {
            recur(result, curr + "(", n , open + 1, close);
        }
        if (open > close) {
            recur(result, curr + ")", n , open , close + 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        if(n == 1){
            return {"()"};
        }
        vector<string> result;
        recur(result , "" , n , 0 , 0);
        return result;
    }
};
