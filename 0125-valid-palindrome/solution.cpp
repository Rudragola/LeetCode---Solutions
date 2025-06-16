class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned;
        for(char c: s){
            if(isalnum(c)){
                cleaned += tolower(c);
            }
        }

        int i = 0;
        int j = cleaned.length()-1;
        while(i<j){
            if(cleaned[i] != cleaned[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};
