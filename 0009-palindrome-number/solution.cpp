class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0){
            return false;
        }
        int temp = x;
        long long num = 0;
        while(x!=0){
            int lastDigit = x%10;
            num= num*10 + lastDigit;
            x/=10;
        }
        if(temp == num){
            return true;
        }else{
            return false;
        }
    }
};
