class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long low = 0, high = num;
        
        while(low <= high){
            long long mid  = low + (high - low) / 2;
            long long temp = (mid-1) + mid + (mid+1);
            if(temp == num){
                return {mid-1, mid, mid+1};
            }
            if(temp > num)
                high = mid-1;
            else
                low = mid+1;
        }
        return {};
    }
};