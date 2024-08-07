class Solution {
public:
    int checkRecord(int n) {
        memset(t, -1, sizeof(t));
        return solve(n, 0, 0);
    }
private:
    int M = 1e9+7;
    int t[100001][2][3];

    int solve(int n, int absent, int consecutive_late) {

        if(absent >= 2 || consecutive_late >= 3) {
            return 0;
        }

        if(n == 0)
            return 1;
        
        if(t[n][absent][consecutive_late] != -1) {
            return t[n][absent][consecutive_late];
        }

        int A = solve(n-1, absent+1, 0) % M;
        int L = solve(n-1, absent, consecutive_late+1) % M;
        int P = solve(n-1, absent, 0) % M;

        return t[n][absent][consecutive_late] = ((A + L) % M + P) % M;
    }
};