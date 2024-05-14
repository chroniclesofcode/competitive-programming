class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string, vector<int>> m;
    unordered_map<string, vector<string>> c;
    void set(string key, string value, int timestamp) {
        m[key].push_back(timestamp);
        c[key].push_back(std::move(value));
    }
    
    string get(string key, int timestamp) {
        auto &vec = m[key];
        auto it = upper_bound(vec.begin(), vec.end(), timestamp);
        if (it == vec.begin()) return "";
        it--;
        return c[key][it-vec.begin()];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
