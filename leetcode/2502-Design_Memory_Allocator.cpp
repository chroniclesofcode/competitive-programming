class Allocator {
public:
    int n;
    vector<pair<int,int>> m[1001];
    int mem[1001];
    Allocator(int _n) {
        n = _n;
    }
    
    int allocate(int size, int mID) {
        int ct = 0;
        for (int i = 0; i < n; i++) {
            if (mem[i] == 0) ct++;
            else ct = 0;
            if (ct == size) {
                for (int j = 0; j < size; j++) {
                    mem[i-j] = mID;
                }
                int first = i-(size-1);
                m[mID].push_back({first, size});
                return first;
            }
        }
        return -1;
    }
    
    int free(int mID) {
        int ret = 0;
        for (auto& p : m[mID]) {
            for (int i = 0; i < p.second; i++) {
                mem[p.first+i] = 0;
            }
            ret += p.second;
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
