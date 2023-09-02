class LRUCache {
public:
    int cap;
    list<int> l;
    unordered_map<int, list<int>::iterator> m;
    unordered_map<int, int> kv;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (kv.find(key) == kv.end()) {
            return -1;
        }
        auto it = m[key];
        l.erase(it);
        l.push_front(key);
        m[key] = l.begin();
        return kv[key];
    }
    
    void put(int key, int value) {
        auto f = kv.find(key);
        // new value
        if (f == kv.end()) {
            kv[key] = value;
            if (l.size() == cap) {
                int rmk = l.back();
                kv.erase(rmk);
                m.erase(rmk);
                l.pop_back();
            }
            l.push_front(key);
            m[key] = l.begin();
            return;
        }
        // already exists
        auto it = m[key];
        l.erase(it);
        l.push_front(key);
        m[key] = l.begin();
        kv[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
