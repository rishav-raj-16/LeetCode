class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto a:nums)
         m[a]++;
        
        for(auto x:m)
         if(x.second==1)
          return (x.first);
        
        return -1;
    }
};