class SORTracker {
public:
    #define pp pair<int, string>
    struct comp {
        bool operator()(const pp a, const pp b) const {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        }
    };
    struct compless {
        bool operator()(const pp a, const pp b) const {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        }
    };
    bool pcmp(const pp a, const pp b) const {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
    }

    multiset<pp, compless> l; // highest first
    multiset<pp, comp> r; // lowest first, .begin() is intersection
    SORTracker() {
    }

    void debug() {
        cout << "l: ";
        for (auto it = l.begin(); it != l.end(); it++) {
            cout << it->first << "," << it->second << " ";
        }
        cout << "\nr: ";
        for (auto it = r.begin(); it != r.end(); it++) {
            cout << it->first << "," << it->second << " ";
        }
        cout << endl;
    }
    
    void add(string name, int score) {
        if (l.size() == 0) {
            r.insert({score,name});
            return;
        }
        if (pcmp(make_pair(score,name), *l.begin())) {
            r.insert(*l.begin());
            l.erase(l.begin());
            l.insert({score,name});
        } else {
            r.insert({score,name});
        }
    }
    
    string get() {
        string val = r.begin()->second;
        l.insert(*r.begin());
        r.erase(r.begin());
        return val;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
