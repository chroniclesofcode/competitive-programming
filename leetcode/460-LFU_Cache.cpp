class LFUCache {
public:
    int cap;
    vector<list<array<int,2>>> uses;
    unordered_map<int, list<array<int,2>>::iterator> m;
    unordered_map<int, int> nums;
    int bottom = 0;
    int top = 0;
    int tot = 0;
    LFUCache(int capacity) {
        cap = capacity;
        uses.resize(100); // uses.resize(2*(int)1e5 + 1);
    }

    void increase(int key) {
        int i = nums[key]++;
        auto it = m[key];
        if (i == top) {
            top++;
        }
        auto upd = uses[i+1].insert(uses[i+1].end(), *it);
        uses[i].erase(it);
        m[key] = upd;
        if (i == bottom && uses[i].empty()) {
            bottom++;
        }
    }

    int get(int key) {
        if (nums[key] == 0) return -1;
        int ret = (*m[key])[1];
        increase(key);
        return ret;
    }
    
    void put(int key, int value) {
        int i = nums[key];
        if (i != 0) {
            (*m[key])[1] = value;
            increase(key);
            return;
        }
        if (tot == cap) {
            auto remit = uses[bottom].begin();
            m.erase((*remit)[0]);
            nums[(*remit)[0]] = 0;
            uses[bottom].erase(remit);
        } else {
            tot++;
        }
        bottom = 1;
        auto it = uses[1].insert(uses[1].end(), {key, value});
        m[key] = it;
        nums[key] = 1;
        if (top == 0) {
            top++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
