class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int low = 0, high = position[n-1] - position[0]; 
        
        while(low < high){
            int mid = low + (high - low + 1) / 2;
            int count = 1, prev = position[0];
            
            for(int i = 1; i < n; i++){
                if(position[i] - prev >= mid){
                    count++;
                    prev = position[i];
                }
            }
            
            if(count >= m)
                low = mid;
            else
                high = mid - 1;
        }
        
        return low;
    }
};