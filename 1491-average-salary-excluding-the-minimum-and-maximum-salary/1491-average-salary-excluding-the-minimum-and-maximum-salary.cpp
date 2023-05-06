class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size() - 2;
        int mx = *max_element(salary.begin(),salary.end()), mn = *min_element(salary.begin(),salary.end());
        double ans = accumulate(salary.begin(),salary.end(),0) - mn - mx;
        return ans / n;
    }
};