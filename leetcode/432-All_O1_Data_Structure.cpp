class AllOne {
public:
    /*
        std::list, unordered_map of value to
        unordered_set of list iterators
        It's going to be one long linked list
    */
    using P = pair<int, std::unordered_set<string>>;
    using Lit = std::list<P>::iterator;
    const static int MX = (int)1e4 * 5 + 1;
    std::list<P> l;
    unordered_map<string, Lit> m;

    AllOne() {
        
    }

    void inc(string key) {
        auto it = m.find(key);
        if (it == m.end()) {
            if (l.empty()) {
                l.push_front({1, {key}});
            } else {
                if (l.begin()->first != 1) {
                    l.push_front({1, {key}});
                } else {
                    (l.begin()->second).insert(key);
                }
            }
            m[key] = l.begin();
            return;
        }
        int num = it->second->first;
        Lit curr = it->second;
        Lit next = std::next(curr);
        if (next == l.end() || next->first != num + 1) {
            if (curr->second.size() == 1) {
                (curr->first)++;
                return;
            }
            m[key] = l.insert(next, {num+1, {key}});
        } else {
            next->second.insert(key);
            m[key] = next;
        }
        if (curr->second.size() == 1) l.erase(curr);
        else curr->second.erase(key);
    }
    
    void dec(string key) {
        auto it = m.find(key);
        int num = it->second->first;
        Lit curr = it->second;
        if (num == 1) {
            curr->second.erase(key);
            if (curr->second.empty()) l.erase(curr);
            m.erase(key);
            return;
        }
        if (curr == l.begin()) {
            if (curr->first > 1 && curr->second.size() == 1) {
                (curr->first)--;
                return;
            }
            l.push_front({ num-1, {key}});
            m[key] = l.begin();
            return;
        }
        auto prev = std::prev(curr);
        if (prev->first == num-1) {
            prev->second.insert(key);
            m[key] = prev;
        } else {
            if (curr->second.size() == 1) {
                (curr->first)--;
                return;
            } else {
                m[key] = l.insert(curr, {num-1, {key}});
            }
        }
        if (curr->second.size() == 1) l.erase(curr);
        else curr->second.erase(key);
    }
    
    string getMaxKey() {
        if (l.empty()) return "";
        return *(prev(l.end())->second.begin());
    }
    
    string getMinKey() {
        if (l.empty()) return "";
        return *(l.begin()->second.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
