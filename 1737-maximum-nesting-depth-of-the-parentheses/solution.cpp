class Solution {
public:
    int maxDepth(string s) {
        int count  = 0;
        int maxi = 0;
        for(auto it:s){
            if(it == '('){
                count++;
            }else if( it == ')'){
                maxi = max(maxi , count);
                count--;
                
            }
        }
        return maxi;
    }
};
