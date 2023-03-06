class Solution {
public:
    bool find(vector<int>& ar, int a){
        for(auto x:ar)
        if(x == a)
        return 1;

        return 0;
    }

    int findKthPositive(vector<int>& arr, int k) {
        int ans;
        for(int i = 1; i<= 1000, k > 0; i++){
            if(find(arr,i))
            continue;
            else{
                ans = i;
                k--;
            }
        }
        return ans;
    }
};