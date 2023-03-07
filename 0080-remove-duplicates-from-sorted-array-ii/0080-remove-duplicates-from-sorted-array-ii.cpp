class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int cnt=1;
       for(int i=1;i<nums.size();++i)
       {
           if(nums[i-1]==nums[i])  
           {
               if(cnt==2)
               {
                  int index=i;
                  while(i<nums.size() && nums[i-1]==nums[i]) i++;
                  nums.erase(nums.begin()+index,nums.begin()+i);
                  i=index-1;
                  cnt=1;
                }
               else ++cnt;
           }
           else cnt=1;
       }
       return nums.size();
    }
};