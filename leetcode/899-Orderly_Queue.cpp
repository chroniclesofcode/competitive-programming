class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k >= 2) {
            sort(s.begin(), s.end());
            return s;
        } else if (k == 0) {
            return s;
        }
        // k == 1
        string mini = s;
        int sz = s.size();
        for (int i = 0; i < sz; i++) {
            s += s[i];
            mini = min(mini, s.substr(i+1));
        }
        return mini;
    }
};
