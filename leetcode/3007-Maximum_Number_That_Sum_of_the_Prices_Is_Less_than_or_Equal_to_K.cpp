class Solution {
public:
    #define ll long long
    long long findMaximumNumber(long long k, int x) {
        ll lo = 0;
        ll hi = (ll)1e15;
        ll ans = 0;
        while (lo <= hi) {
            ll mid = lo + (hi - lo)/2;
            ll ct = 0;
            // check number of set bits under mid >= k
            for (int i = x-1; i <= 60; i += x) {
                ll tmp = (mid+1)%(1LL<<(i+1));
                ct += (mid+1-tmp)/2 + max(tmp - (1LL<<(i+1))/2, 0LL);
            }
            bool flag = ct <= k;
            if (flag) {
                ans = max(ans, mid);
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        return ans;
    }
};
