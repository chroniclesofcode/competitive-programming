class CountIntervals {
public:
    #define arr pair<int,int>
    int ct = 0;
    multiset<arr> s;
    CountIntervals() {
        
    }
    
    void add(int left, int right) {
        auto it = s.lower_bound({left, -1});
        arr add = {left, right};
        if (it != s.begin() && s.size()) {
            auto prev = it;
            prev--;
            if (prev->first <= left && prev->second >= right) {
                return;
            }
            if (prev->second >= left) {
                add.first = min(add.first, prev->first);
                it = prev;
                //cout << "yahllo " << left << ' ' << right << "\n";
            }
        }
        while (it != s.end() && right >= it->first) {
            ct -= it->second - it->first + 1;
            add.second = max(add.second, it->second);
            auto prev = it;
            it++;
            s.erase(prev);
        }
        ct += add.second - add.first + 1;
        s.insert(add);
    }
    
    int count() {
        return ct;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
