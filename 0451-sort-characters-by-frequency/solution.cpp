class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char,int> mpp;
        string ans;
        for(auto it : s){
            mpp[it]++;
        }

        vector<string> bucket(n+1);
        for(auto &p : mpp){
            bucket[p.second].push_back(p.first);
        }

        ans.reserve(n);
        for(int f = n;f>=1;f--){
            for(auto it : bucket[f]){
                ans.append(f,it);
            }
        }
        return ans;
        
    }
};
