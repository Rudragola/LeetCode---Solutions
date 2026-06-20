class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        /* sort(s.begin() , s.end());
        sort(t.begin() , t.end());
        return s == t; */

        unordered_map<int,int> mpp1;
        int n= s.length();
        for(int i = 0;i<n;i++){
            mpp1[s[i]]++;
        }

        for(auto it:t){
            if(mpp1[it] == 0) return false;
            mpp1[it]--;
        }
        return true;
    }
};
