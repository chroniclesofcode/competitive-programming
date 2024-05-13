class Solution {
public:
    string res;
    int big = 0;
    int mp[27], nm[11];
    vector<int> lv[10];
    bool flag = false;
    void assign(int l, int st, int sum, int carry) {
        if (flag) return;
        if (st == lv[l].size()) {
            // check validity
            int nsum = sum + carry;
            int lo = nsum % 10;
            int hi = nsum / 10;
            int &v = mp[res[l]-'A'];
            int tmp = v;
            if (v >= 0 && v != lo) return;
            if (v < 0 && nm[lo]) return;
            if (hi > 0) {
                if (l == big-1) {
                    if (l+1 >= res.size()) return;
                    int val = mp[res[l+1]-'A'];
                    if (val >= 0 && val != hi) return;
                }
            } else if (l == big-1 && l+1 < res.size()) return;
            v = lo;
            nm[lo] = 1;
            dfs(l+1, hi);
            v = tmp;
            nm[lo] = 0;
            return;
        }
        if (mp[lv[l][st]] >= 0) {
            assign(l, st+1, sum+mp[lv[l][st]], carry);
            return;
        }
        for (int j = 0; j <= 9; j++) {
            if (nm[j]) continue;
            int c = lv[l][st];
            int tmp = mp[c];
            if (j == 0 && tmp == -2) continue;
            nm[j] = 1;
            mp[c] = j;
            assign(l, st+1, sum+j, carry);
            nm[j] = 0;
            mp[c] = tmp;
        }
    }
    void dfs(int l, int carry) {
        if (flag) return;
        if (l == big) {
            flag = true; 
            return;
        }
        assign(l, 0, 0, carry);
    }
    bool isSolvable(vector<string>& words, string result) {
        res = std::move(result);
        reverse(res.begin(), res.end());
        for (int i = 0; i < 26; i++) mp[i] = -1;
        for (int i = 0; i < words.size(); i++) {
            int sz = words[i].size();
            if (sz > 1)
                mp[words[i][0]-'A'] = -2;
            reverse(words[i].begin(), words[i].end());
            for (int j = 0; j < sz; j++) {
                lv[j].push_back(words[i][j]-'A');
            }
            big = max(big, (int)words[i].size());
        }
        if (res.size() < big) return false;
        if (res.size() - big >= 2) return false;
        dfs(0, 0);
        return flag;
    }
};
