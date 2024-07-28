class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> mat(26,vector<long long>(26,1e9));
        
        for (int i = 0; i < cost.size(); i++) {
            int s = original[i] - 'a';
            int t = changed[i] - 'a';
            mat[s][t] = min(mat[s][t],(long long)cost[i]);
        }
        
        floyd_shortest_path(mat);
        
        long long ans = 0;
        for(int i = 0; i < source.size(); i++) {
            if(source[i] != target[i]) {
                if(mat[source[i]-'a'][target[i] - 'a'] == 1e9) return -1;
                ans += mat[source[i]-'a'][target[i] - 'a'];
            }
        }
        return ans;
    }
    
private:
    void floyd_shortest_path(vector<vector<long long>>& mat) {
        for(int k = 0; k <26; k++) {
            for(int i= 0; i < 26; i++) {
                for(int j = 0 ; j < 26; j++) {
                    mat[i][j] = min(mat[i][j],mat[i][k] + mat[k][j]);
                }
            }
        }
    }
};