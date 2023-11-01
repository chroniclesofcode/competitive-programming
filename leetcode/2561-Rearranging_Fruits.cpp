class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        unordered_map<int, int> ct;
        int n = b1.size();
        int small = INT_MAX;
        for (int i = 0; i < n; i++) {
            ct[b1[i]]++;
            ct[b2[i]]++;
            small = min({small, b1[i], b2[i]});
        }
        for (auto e : ct) {
            if (e.second % 2 == 1) {
                return -1;
            }
        }
        vector<int> res1, res2;
        unordered_map<int, int> m, m2;
        for (int i = 0; i < n; i++) {
            if (m[b1[i]] == ct[b1[i]]/2) {
                res1.push_back(b1[i]);
            } else {
                m[b1[i]]++;
            }
            if (m2[b2[i]] == ct[b2[i]]/2) {
                res2.push_back(b2[i]);
            } else {
                m2[b2[i]]++;
            }
        }
        if (res1.size() != res2.size()) return -1;
        sort(res1.begin(), res1.end());
        sort(res2.begin(), res2.end());
        int sz = res1.size();
        int lim = sz/2;
        long long tmp = 0;
        for (int i = 0; i < lim; i++) {
            tmp += min({res1[i], res2[sz-i-1], small*2});
            tmp += min({res2[i], res1[sz-i-1], small*2});
        }
        if (sz % 2 == 1) tmp += min({res1[lim], res2[lim], small*2});
        return tmp;
    }
};
