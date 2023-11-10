class Solution {
public:
    #define LL long long
    const static int MX = (int)1e5+1;
    LL power[MX];
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        for (int i = 0; i < n; i++) {
            int llim = max(0, i - r);
            int rlim = min(n-1, i + r);
            power[llim] += stations[i];
            power[rlim+1] -= stations[i];
        }
        LL big = 0;
        for (int i = 0; i < n; i++) {
            power[i] = i == 0 ? power[i] : power[i] + power[i-1];
            big = max(big, power[i]);
        }
        LL lo = 0; LL hi = big + k;
        LL ans = 0;
        vector<LL> tmp(n+1);
        while (lo <= hi) {
            LL mid = lo + (hi - lo) / 2;
            bool flag = true;
            int pref = 0;
            int remain = k;
            memset(&tmp[0], 0, tmp.size() * sizeof tmp[0]);
            for (int i = 0; i < n; i++) {
                if (power[i] + pref < mid) {
                    int rem = mid - power[i] - pref;
                    if (remain < rem) {
                        flag = false; 
                        break;
                    }
                    tmp[i] += rem;
                    tmp[min(n,i+2*r)] -= rem;
                    remain -= rem;
                }
                pref += tmp[i];
            }
            
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
