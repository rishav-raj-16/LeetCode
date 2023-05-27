class Solution {
public:
    int kthFactor(int n, int k) {
        int ans;
        vector<int> fList;        // factor list
        
        for(int i = 1; i <= sqrt(n); i++)
            if(n % i == 0){
                if(n / i == i){
                    fList.push_back(i);
                }
                else{
                    fList.push_back(i);
                    fList.push_back(n/i);
                }
            }
        sort(fList.begin(),fList.end());
        if(k > fList.size())
            return -1;
        return fList[k-1];
    }
};