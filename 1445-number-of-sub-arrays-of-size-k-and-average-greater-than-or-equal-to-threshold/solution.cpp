class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int winSum = 0;
        int count  =0 ;
        for(int i =0;i<k;i++){
            winSum += arr[i];
        }

        if(winSum/k >= threshold){
                count++;
        }

        int i = 0;
        int j = k; 

        while(j<n && i<j){
            
            winSum+=arr[j];
            winSum-=arr[i];

            if(winSum/k >= threshold){
                count++;
            }

            i++;
            j++;
        }
        return count;
    }
};
