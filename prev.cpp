class Solution {
public:
    string clearStars(string s) {
        using arr2 = array<int,2>;
        set<arr2> l;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                if (l.empty()) continue;
                auto it = l.begin();
                s[(*it)[1]] = '.';
                l.erase(it);
                s[i] = '.';
            } else {
                l.insert({s[i]-'a', i});
            }
        }
        string ret;
        for (int i = 0; i < n; i++) {
            if (s[i] != '.') ret.push_back(s[i]);
        }
        return ret;
    }
};
