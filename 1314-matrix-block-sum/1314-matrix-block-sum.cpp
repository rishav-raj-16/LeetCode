class Solution {
public:
    int sum(int r1,int c1,int r2,int c2,vector<vector<int>>& mat){
        int res=0;
        for(int i=r1;i<=r2;i++){
            for(int j=c1;j<=c2;j++)
              res+=mat[i][j];
        }
        return res;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int r1=i-k<0?0:i-k;
                int r2=i+k>=n?n-1:i+k;
                int c1=j-k<0?0:j-k;
                int c2=j+k>=m?m-1:j+k;
                ans[i][j]=sum(r1,c1,r2,c2,mat);
            }
        }
        return ans;
    }
};