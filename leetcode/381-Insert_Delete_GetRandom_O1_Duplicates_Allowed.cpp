/*
    u_map -> u_set of indices of elements
    also, a vector which contains everything
*/
class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> m;
    vector<int> elems;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool ret = m.find(val) == m.end();
        elems.push_back(val);
        m[val].insert(elems.size()-1);
        return ret;
    }
    
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        int rm = *m[val].begin();
        int sval = elems.back();
        int sidx = elems.size() - 1;
        swap(elems[rm], elems[sidx]);
        elems.pop_back();
        m[val].erase(rm);
        if (!(val == sval && sidx == rm)) {
            m[sval].erase(sidx);
            m[sval].insert(rm);
        }
        if (m[val].size() == 0) m.erase(val);
        return true;
    }
    
    int getRandom() {
        return elems[rand() % elems.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
