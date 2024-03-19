class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        map<char, int> mp;

        for (char i : tasks) {
            mp[i]++; 
        }
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            if (it->second)
                pq.push(it->second);
        }

        int time = 0; 
        while (!pq.empty()) {
            vector<int> remain;
            int cycle = n + 1; 
            while (cycle and !pq.empty()) {
                int max_freq = pq.top(); 
                pq.pop();
                if (max_freq > 1) {  
                    remain.push_back(max_freq - 1);
                }
                ++time;
                --cycle;
            }

            for (int count : remain) {
                pq.push(count);
            }
            if (pq.empty()) break;
            time += cycle; 
        }
        return time;
    }
};
