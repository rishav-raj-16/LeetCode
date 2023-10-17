class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> q;
        int ans = 0;
        
        q.push(a);
        q.push(b);
        q.push(c);
        
        while(true) {
            a = q.top();
            q.pop();
            b = q.top();
            q.pop();
            
            if(a == 0 || b == 0) 
                break;
            
            ans++;
            q.push(--a);
            q.push(--b);
        }
        return ans;
    }
};