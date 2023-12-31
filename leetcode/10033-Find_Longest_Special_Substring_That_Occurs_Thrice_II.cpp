class Solution {
public:
    int maximumLength(string s) {
        cout << s << '\n';
        int n = s.size();
        vector<int> ct(26, 0);
        int longest = 1;
        map<int, int, greater<int>> occ[26];
        ct[s[0]-'a']++;
        occ[s[0]-'a'][1]++;
        for (int i = 1; i < n; i++) {
            int c = s[i] - 'a';
            if (s[i] == s[i-1]) {
                longest++;
            } else {
                longest = 1;
            }
            ct[c] = max(ct[c], longest);
            occ[c][longest]++;
        }
        int ans = -1;
        for (int i = 0; i < 26; i++) {
            auto top = occ[i].begin();
            int tmp = top->first >= 3 ? top->first - 2 : -1;
            int cumu = 0;
            for (auto& it : occ[i]) {
                cumu += it.second;
                if (cumu >= 3) {
                    tmp = max(tmp, it.first);
                    break;
                }
            }
            ans = max(ans, tmp);
        }
        return ans;
    }
};
