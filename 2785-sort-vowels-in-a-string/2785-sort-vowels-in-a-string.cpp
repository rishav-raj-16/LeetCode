class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        set<char> list({'A','E','I','O','U','a','e','i','o','u'});
        
        for(auto it:s)
            if(list.find(it) != list.end())
                vowels.push_back(it);
        sort(vowels.begin(),vowels.end());
        
        int i = 0;
        for(int j = 0; j < s.size(); j++)
            if(list.find(s[j]) != list.end())
                s[j] = vowels[i++];
        
        return s;
    }
};