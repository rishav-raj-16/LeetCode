class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0, j = 0, ans = 0;
        int n = arr.size();
        while(j < k)
            sum += arr[j++];
        if(sum / k >= threshold)
            ans++;
        for(int i = 1; i < n-k+1; i++){
            sum -= arr[i-1];
            sum += arr[i+k-1];
            if(sum / k >= threshold)
            ans++;
        }
        return ans;
    }
};