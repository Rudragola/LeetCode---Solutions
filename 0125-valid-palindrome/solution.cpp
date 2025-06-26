class Solution {
public:
    bool isPalindrome(string s) {
         /* string cleaned;
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
        return true; */


        //RECURSION VERSION

        return check(s , 0 ,s.length() - 1);

        
    }

    bool check(string& s , int left , int right){
            
            //if starting character is not alphanumeric move ahead
            while(left<right && !isalnum(s[left])) left++;

            //if ending character is not alphanumeric move backward
            while(left<right && !isalnum(s[right])) right--;

            
            //base case
            if(left >= right) return true;

            //check 
            if(tolower(s[left]) != tolower(s[right])) return false;

            //recursion case
            return check(s , left+1 , right-1);

        }
}; 

        
