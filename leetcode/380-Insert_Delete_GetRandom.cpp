class RandomizedSet {
public:
    unordered_map<int,int> m; // value to index
    vector<int> v; // index to value
    int sz = 1;
    std::mt19937 rng;
    RandomizedSet() {
        v.push_back(0);
    }
    
    bool insert(int val) {
        if (m[val] > 0) return false;
        if (v.size() <= sz) {
            v.push_back(val);
        } else {
            v[sz] = val;
        }
        m[val] = sz++;
        return true;
    }
    
    bool remove(int val) {
        if (m[val] <= 0) return false;
        int idx = m[val];
        v[idx] = v[sz-1];
        m[v[sz-1]] = idx;
        m[val] = 0;
        sz--;
        return true;
    }
    
    int getRandom() {
        std::uniform_int_distribution<int> gen(1, sz-1); // uniform, unbiased
        int r = gen(rng);
        return v[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
