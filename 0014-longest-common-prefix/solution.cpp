class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        /* string prefix = strs[0];
        for(int i = 1;i<strs.size();i++){
            while(strs[i].find(prefix) != 0){
                prefix.pop_back();
                if(prefix.empty()) return "";
            }
        }
        return prefix; */
        int n = strs.size();
        sort(strs.begin() , strs.end());
        string ans = "";
        string first = strs[0];
        string last = strs[n-1];
        for(int i = 0;i<min(first.length() , last.length());i++){
            if(first[i] == last[i]){
                ans.push_back(first[i]);
            }
            else if(i == 0 && first[i] != last[i]){
                return ans;
            }else{
                break;
            }
        }
        return ans;
    }
};
