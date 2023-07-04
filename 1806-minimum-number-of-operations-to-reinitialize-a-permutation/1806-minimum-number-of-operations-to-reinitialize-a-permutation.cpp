class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm, temp;
        int ans = 0;
        for(int  i = 0; i < n; i++)
            perm.push_back(i);
        temp = perm;
        while(true){
            vector<int> arr(n);
            for(int i = 0; i < n; i++){
                if(i % 2 == 0)
                    arr[i] = temp[i/2];
                else
                    arr[i] = temp[n / 2 + (i - 1) / 2];
            }
            ans++;
            temp = arr;
            if(arr == perm)
                break;
        }
        return ans;
    }
};