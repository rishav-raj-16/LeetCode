class Solution {
private: set<int> s; 
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> ans;
        sieve_of_eratosthenes(n);
        
        for(auto it: s){
            if(it > n/2) break;
            int temp = n - it;
            if(s.find(temp) != s.end())
                ans.push_back({it,temp});
        }
        return ans;
    }
    void sieve_of_eratosthenes(int n)
    {
        bool is_prime[n + 1];
        memset(is_prime, true, sizeof(is_prime));
        is_prime[0] = is_prime[1] = false;
        for (int p = 2; p * p <= n; p++) {
            if (is_prime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    is_prime[i] = false;
                }
            }
        }
        for (int i = 2; i <= n; i++) {
            if (is_prime[i]) {
                s.insert(i);
            }
        }
    }
 
};