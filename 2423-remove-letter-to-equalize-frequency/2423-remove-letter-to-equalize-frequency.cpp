class Solution 
{
public:
    bool equalFrequency(string word) 
    {
        vector<int> mp(26, 0); 
        
        for(auto it:word) //storing frequency
            mp[it-'a']++;

        for(int i=0; i<26; i++) 
        {
            if(mp[i]==0) continue;
            mp[i]--;
            
            int fl=0, cnt=0, fl2=0;
            for(int i=0; i<26; i++) {
                if(mp[i]==0) continue;
                
                if(fl==0)  //storing frequency of 1st char in cnt
                {
                    cnt = mp[i];
                    fl=1;
                }
                
                if(mp[i]!=cnt) 
                {
                    fl2=1; 
                    break;
                }
            }
            if(fl2==0) return true; 
            
            mp[i]++;        }
        return false;
    }
};