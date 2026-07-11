class Solution {
public:

    long long pow(long long base ,long long exp , long long MOD){
        long long result = 1;
        base %= MOD;

        while(exp > 0){
            if(exp % 2 == 1){
                result = (result * base)%MOD;
                exp -= 1;
            }
            base = (base*base)%MOD;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;
        long long MOD = 1000000007;

        long long ans = pow(5,even,MOD) * pow(4 , odd,MOD) % MOD;
        return (int)ans;
    }
};
