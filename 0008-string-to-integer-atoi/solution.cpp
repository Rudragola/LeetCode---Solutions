class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int sign = 1;
        int i = 0;
        long long ans = 0;
        while(i<n && s[i] == ' ') i++;

        if(i<n && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-'){
                sign = -1;
            }
            i++;
        }

        while(i<n && (s[i] >= '0' && s[i] <='9')){
            ans = ans * 10 + (s[i]- '0');

            if(sign * ans >= INT_MAX)return INT_MAX;
            if(sign * ans <= INT_MIN)return INT_MIN;
            i++;
        }
        return  (int)(sign*ans);
    }
};
