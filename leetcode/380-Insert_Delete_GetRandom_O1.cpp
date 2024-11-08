class RandomizedSet {
public:
    unordered_map<int, int> loc;
    vector<int> store;
    RandomizedSet() {}

    
    bool insert(int val) {
        if (loc.find(val) != loc.end()) return false;
        loc[val] = store.size();
        store.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (loc.find(val) == loc.end()) return false;
        int b = store.back();
        swap(store[loc[b]], store[loc[val]]);
        swap(loc[b], loc[val]);
        store.pop_back();
        loc.erase(val);
        return true;
    }
    
    int getRandom() {
        return store[rand() % store.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
