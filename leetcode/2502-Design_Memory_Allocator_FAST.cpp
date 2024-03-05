class Allocator {
public:
    int n;
    vector<pair<int,int>> m[1001];
    set<pair<int,int>> mem;
    Allocator(int _n) {
        n = _n;
        mem.insert({0, n});
    }
    
    int allocate(int size, int mID) {
        for (auto it = mem.begin(); it != mem.end(); it++) {
            if (it->second >= size) {
                int first = it->first;
                if (it->second > size) {
                    mem.insert({first+size, it->second-size});
                }
                m[mID].push_back({first, size});
                mem.erase(it);
                return first;
            }
        }
        return -1;
    }
    
    int free(int mID) {
        int ret = 0;
        for (auto& p : m[mID]) {
            ret += p.second;
            int start = p.first, finish = p.first+p.second;
            auto it = mem.lower_bound({p.first, -1});
            auto it2 = it;
            if (it2 != mem.begin() && !mem.empty()) {
                it2--;
                if (it2->first+it2->second >= start) {
                    start = min(start, it2->first);
                    mem.erase(it2);
                }
            }
            if (it != mem.end() && it->first <= finish) {
                finish = max(finish, it->first+it->second);
                mem.erase(it);
            }
            mem.insert({start, finish-start});
        }
        m[mID].clear();
        return ret;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
