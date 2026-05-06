class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> answ;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> cur(i+1 , 0);
            for (int j = 0; j <= i; j++) {
                if (i == j || j == 0) {
                    cur[j] = 1;
                } else {
                    ans = answ[i - 1][j - 1] + answ[i - 1][j];
                    cur[j] = ans;
                }
            }
            answ.push_back(cur);
        }
        return answ;
    }
};
