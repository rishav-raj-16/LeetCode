class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size()-1;
        while(low < high){
            int mid = low + (high - low) / 2;
            if(arr[mid+1] > arr[mid] && arr[mid] > arr[mid-1])
                low = mid;
            else if(arr[mid+1] < arr[mid] && arr[mid] < arr[mid-1])
                high = mid;
            else
                return mid;
        }
        return -1;
    }
};