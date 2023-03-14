class Solution {
public:
    bool check(int totalTrips,vector<int>&time,long long trips)
    {
        long long count=0;
        for(auto i:time)
        {
            count+=trips/i;
            if(count>=totalTrips)return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=1,h=10e14;
        long long ans;
        while(l<=h)
        {
            long long mid=l+(h-l)/2;
            if(check(totalTrips,time,mid))
            {
                ans=mid;
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
    
