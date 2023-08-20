class Solution {
public:
    int minimumSum(int n, int k) {
        int sum = 0, num = 1;
        vector<int>avoid;
        for(int i = 0; i < n; i++){
            if(num >= k){
                sum += num++;
            }
            else if(k - num < num){
                num++, i--;
            }
            else{
                sum += num++;
            }
        }
        return sum;
    }
};