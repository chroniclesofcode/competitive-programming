class Solution {
public:
    string clearStars(string s) {
        using arr2 = array<int,2>;
        auto Custom = [](const arr2 &a, const arr2 &b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        };
        set<arr2, decltype(Custom)> l(Custom);
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
            if (s[i] != '.' && s[i] != '*') ret.push_back(s[i]);
        }
        return ret;
    }
};
