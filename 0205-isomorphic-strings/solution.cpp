class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,char> mpp1;
        unordered_map<char,char> mpp2;

        for(int i = 0;i<s.size();i++){
            char ch = t[i];
            char hc = s[i];
            if(mpp1.find(hc) != mpp1.end() && mpp1[hc] != ch) return false;
            if(mpp2.find(ch) != mpp2.end() && mpp2[ch] != hc) return false;
            mpp1[hc] = ch;
            mpp2[ch] = hc;
        }
        return true;
    }
};
