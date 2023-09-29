class Solution {
public:
    vector<long long> countBlackBlocks(int n, int m, vector<vector<int>>& coordinates) {
        #define ll long long
        vector<ll> ret(5, 0);
        unordered_map<ll, ll> ct;
        for (auto coord : coordinates) {
            ll x = coord[0]; ll y = coord[1];
            // block1
            if (y != m-1 && x != n-1) {
                ll b1 = x*m + y;
                ct[b1]++;
            }
            // block2
            if (y != 0 && x != n-1) {
                ll b2 = x*m + y-1;
                ct[b2]++;
            }
            // block3
            if (x != 0 && y != m-1) {
                ll b3 = (x-1)*m + y;
                ct[b3]++;
            }
            // block4
            if (x != 0 && y != 0) {
                ll b4 = (x-1)*m + y-1;
                ct[b4]++;
            }
        }
        ll tot = (ll)(n-1)*(m-1);
        ll sub = 0;
        for (auto it = ct.begin(); it != ct.end(); it++) {
            ll occ = it->second;
            if (occ > 0) {
                ret[occ]++;
                sub++;
            }
        }
        ret[0] = tot - sub;
        return ret;
    }
};
