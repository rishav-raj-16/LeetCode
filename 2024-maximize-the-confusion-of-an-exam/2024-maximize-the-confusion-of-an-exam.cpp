class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int window_start = 0;
        int max_streak = 0;
        int max_count = 0;
        unordered_map<char, int> freq;
    
        for (int i = 0; i < n; i++) {
            freq[answerKey[i]]++;
            max_count = max(max_count, freq[answerKey[i]]);
    
            if ((i - window_start + 1) - max_count > k) {
                freq[answerKey[window_start]]--;
                window_start++;
            }
    
            max_streak = max(max_streak, i - window_start + 1);
        }
    
        return max_streak;
    }
};