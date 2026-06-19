class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long N = n*n;
        long long SN = (N*(N+1))/2;
        long long S2N = (N*(N+1)*(2*N+1))/6;
        long long s = 0;
        long long s2n = 0;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                s += (long long)grid[i][j];
                s2n += ((long long)grid[i][j] * (long long)grid[i][j]);
            }
        }
        long long val1 = s - SN;
        long long val2 = s2n - S2N;
        long long val3 = val2 / val1;

        long long x = (val1 + val3)/2;
        long long y = val3 - x;

        return {(int)x,(int)y};

    }
};
