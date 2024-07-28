class Solution {
public:
    int passThePillow(int n, int time) {
        int temp = time / (n - 1);
        return temp % 2 == 0 ? (time % (n - 1) + 1) : (n - time % (n - 1));
    }
};