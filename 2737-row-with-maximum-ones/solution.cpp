class Solution {
public:

    int  lowerBound(vector<int> arr , int n ,int x){
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low <=high){
            int mid = low + (high - low)/2;
            if(arr[mid] >= x){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxi = 0;
        int ans  = 0;
    
        for(int i = 0;i<n;i++){
            sort(mat[i].begin() , mat[i].end());
            int cnt = lowerBound(mat[i] , m , 1);
            cnt = m - cnt;
            if(cnt > maxi) {
                maxi = cnt;
                ans = i;
            }
        }
        return {ans , maxi};
    }
};
