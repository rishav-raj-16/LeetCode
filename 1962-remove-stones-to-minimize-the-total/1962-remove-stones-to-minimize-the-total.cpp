class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> store;
        
        for(auto it:piles)
            store.push(it);
        
        for(int i = 0; i < k; i++){
            int j = store.top();
            store.pop();
            j = j - (j/2);
            cout<<j<<" ";
            store.push(j);
        }
        
        int ans = 0;
        
        while(!store.empty()){
            ans += store.top();
            store.pop();
        }
        
        return ans;
    }
};