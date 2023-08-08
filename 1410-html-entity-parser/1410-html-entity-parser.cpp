class Solution {
public:
    string entityParser(string text) {
        unordered_map<string,string> mp = {{"&apos;", "'"},{"&quot;", "\""},{"&amp;", "&"},{"&gt;", ">"},{"&lt;", "<"},{"&frasl;", "/"}};
        cout<<text.size();
        
        string res = "";
        int i = 0;
        while(i < text.size()){
            bool found = false;
            for(auto it : mp){
                if(text.substr(i, it.first.size()) == it.first){
                    res += it.second;
                    found = true;
                    i += it.first.size();
                    break;
                }
            }
            if(found == false){
                res += text[i];
                i++; 
            }
        }
        
        return res;
    }
};