class RandomizedCollection {
public:
    unordered_map<int, unordered_map<int,int>> m;
    vector<int> v; // index to value
    int sz = 1;
    std::mt19937 rng;
    RandomizedCollection() {
        v.push_back(0);
    }

    bool insert(int val) {
        bool ret = true;
        if (m[val].size() > 0) ret = false;
        if (v.size() <= sz) {
            v.push_back(val);
        } else {
            v[sz] = val;
        }
        m[val][sz++] = 1;
        return ret;
    }
    
    bool remove(int val) {
        if (m[val].size() == 0) return false;
        int idx = m[val].begin()->first;
        if (idx == sz-1) {
            m[val].erase(idx);
        } else {
            v[idx] = v[sz-1];
            m[val].erase(idx);
            m[v[sz-1]].erase(sz-1);
            m[v[sz-1]][idx] = 1;
        }
        sz--;
        return true;
    }
    
    int getRandom() {
        std::uniform_int_distribution<int> gen(1, sz-1); // uniform, unbiased
        int r = gen(rng);
        return v[r];
    }
};
