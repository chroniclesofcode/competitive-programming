class Solution {
public:
    #define LL long long
    vector<int> c;
    // how many multiples up to a value
    LL check(LL val) {
        LL ans = 0;
        LL mask = 0;
        for (int i = 0; i < c.size(); i++) mask |= 1 << i;
        for (int i = 1; i <= mask; i++) {
            LL div = 0, mult = 0, lcm = 0, ct = 0;
            for (int j = 0; j < c.size(); j++) {
                if (i & (1 << j)) {
                    mult = lcm == 0 ? c[j] : lcm * c[j];
                    div = lcm == 0 ? c[j] : std::gcd(lcm, c[j]);
                    lcm = lcm == 0 ? c[j] : mult / div;
                    ct++;
                }
            }
            ans += ct % 2 == 0 ? -(val/lcm) : val/lcm;
        }
        return ans;
    }
    
    long long findKthSmallest(vector<int>& coins, int k) {
        c = std::move(coins);
        sort(c.begin(), c.end());
        c.erase(std::unique(c.begin(), c.end()), c.end());
        if (c[0] == 1) return k;
        LL lo = 1, hi = LLONG_MAX, ans = LLONG_MAX;
        while (lo <= hi) {
            LL mid = lo + (hi - lo) / 2;
            LL nums = check(mid);
            if (nums < k) {
                lo = mid+1;
            } else if (nums > k) {
                hi = mid-1;
            } else {
                ans = min(ans, mid);
                hi = mid-1;
            }
        }
        return ans;
    }
};
