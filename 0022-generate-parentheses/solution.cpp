class Solution {
public:

    vector<string> answer = {};
    vector<char> currentSeq = {};
    void recursion(int index , int sum , int N){

        if(index == N){
            if(sum == 0){
                string ans = "";
                for(int i = 0;i<N;i++){
                    ans += currentSeq[i];
                }
                answer.push_back(ans);
            }
            return;
        }

        //open bracket
        currentSeq.push_back('(');
        recursion(index+1,sum+1,N);
        currentSeq.pop_back();

        //close bracket
        if(sum>=1){
            currentSeq.push_back(')');
            recursion(index+1,sum-1,N);
            currentSeq.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {

        recursion(0,0,n*2);
        return answer;
        
    }
};
