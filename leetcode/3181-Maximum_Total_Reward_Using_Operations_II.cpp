class Solution {
public:
    int maxTotalReward(vector<int>& r) {
        int n = r.size();
        sort(r.begin(), r.end());
        const int MX = (int)1e5 + 1;
        bitset<MX> dp;
        for (int i = 0; i < n; i++) {
            bitset<MX> bs;
            bs.set();
            bs >>= MX - r[i];
            bs &= dp;
            dp |= (bs << r[i]);
            dp.set(r[i], 1);
        }
        for (int i = MX-1; i >= 0; i--) {
            if (dp[i]) return i;
        }
        return 0;
    }
};

