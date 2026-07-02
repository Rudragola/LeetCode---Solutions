class Solution {
public:

    bool ifAlphaNumeric(char ch){
        if((ch>= '0' && ch <= '9') || ('a' <= tolower(ch) && 'z'>= tolower(ch))){
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        int n = s.length();
        int st = 0;
        int end = n - 1;
        while(st < end){
            if(!ifAlphaNumeric(s[st])){
                st++;
                continue;
            }
            if(!ifAlphaNumeric(s[end])){
                end--;
                continue;
            }
            if(tolower(s[st]) != tolower(s[end])){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
};
