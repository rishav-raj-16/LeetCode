class RandomizedSet {
private:
    unordered_set<int> st;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(st.find(val) == st.end()){
            st.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        auto it = st.find(val);
        if(it != st.end()) {
            st.erase(it);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int idx = rand()%st.size();
        return *next(st.begin(),idx);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */