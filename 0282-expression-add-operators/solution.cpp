class Solution {
public:
    vector<string> ans;
    string num;
    int target;
    void recur(int i, long long cur, long long prev, string path) {
        if (i == num.length()) {
            if (cur == target) {
                ans.push_back(path);
            }
        }

        long long curNum = 0;
        string curStr = "";

        for (int j = i; j < num.size(); j++) {
            if (j>i && num[i] == '0')
                break;

            curStr += num[j];
            curNum = curNum * 10 + (num[j] - '0');

            if (i == 0) {
                recur(j + 1, cur + curNum, curNum, path + curStr);
            } else {
                recur(j + 1, cur + curNum, curNum, path + '+' + curStr);

                recur(j + 1, cur - curNum, -curNum, path + '-' + curStr);

                recur(j + 1, cur - prev + (curNum * prev), prev* curNum, path + '*' + curStr);
            }
        }
    }

    vector<string> addOperators(string s, int tar) {
        num = s;
        target = tar;
        recur(0,0,0,"");
        return ans;
    }
};
