/* class Solution {
public:
    bool validPalindrome(string s) {
        int i  =0 ;
        int j = s.length() - 1;
        int count = 0;
        while(i<j){
            if(s[i] != s[j] && count == 0){
                count++;
                s.erase(1,i);
                j--;
            }else if(s[i] != s[j]){
                return false;
            }else{
                i++;
                j--;

            }
            
            
        }
        return true;
    }
}; */

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while (i < j) {
            if (s[i] != s[j]) {
                // Try skipping either s[i] or s[j]
                string skip_i = s;
                string skip_j = s;
                skip_i.erase(i, 1);  // Remove character at i
                skip_j.erase(j, 1);  // Remove character at j

                return isPalindrome(skip_i) || isPalindrome(skip_j);
            }
            i++;
            j--;
        }

        return true;
    }

    bool isPalindrome(const string& str) {
        int i = 0, j = str.length() - 1;
        while (i < j) {
            if (str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};

