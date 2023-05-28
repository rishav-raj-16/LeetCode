class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        vector<int> hash(10,0);
        for(auto it: digits){
            hash[it]++;
        }
        for(int i = 100; i < 999; i+=2){
            vector<int> temp(10,0);
            int num = i;
            
            while(num>0){
                temp[num % 10]++;
                num /= 10;
            }
            
            bool flag = true;
            for(int j = 0; j < 10; j++){
                if(temp[j] > hash[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans.push_back(i);
            }
        }
        return ans;
    }
};