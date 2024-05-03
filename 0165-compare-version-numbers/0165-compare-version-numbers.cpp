class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size(), n2 = version2.size();
        int a = 0, b = 0;
            
        for(int i = 0, j = 0; i < n1 || j < n2; i++,j++) {
            
            while(i < n1 && version1[i] != '.') {
                a = (10*a)+(version1[i++] - '0');
            }
            
            while(j < n2 && version2[j] != '.') {
                b = (10*b)+(version2[j++] - '0');
            }
            
            if(a < b) return -1;
            else if(a > b) return 1;
            
            a = 0, b = 0;
        }
        return 0;
    }
};