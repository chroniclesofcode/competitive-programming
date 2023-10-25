class Solution {
public:
    static const int MX = (int)1e5 + 1;
    long long pref[MX];
    //int valid[MX];
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        int n = packages.size();
        sort(packages.begin(), packages.end());
        long long p = 0;
        for (int i = 0; i < n; i++) {
            p += packages[i];
            pref[i] = p;
        }
        int big = packages[n-1];
        long long ans = LLONG_MAX;
        for (int i = 0; i < boxes.size(); i++) {
            sort(boxes[i].begin(), boxes[i].end());
            int m = boxes[i].size();
            if (boxes[i][m-1] >= big) {
                int prev = -1;
                long long count = 0;
                for (int j = 0; j < m; j++) {
                    auto it = upper_bound(packages.begin(), packages.end(), boxes[i][j]);
                    if (it == packages.begin()) continue;
                    it--;
                    int idx =  it - packages.begin();
                    int diff = idx - prev;
                    if (diff == 0) continue;
                    long long prevpref = prev == -1 ? 0 : pref[idx-diff];
                    count += (long long)diff * boxes[i][j] - (pref[idx] - prevpref);
                    prev = idx;
                    if (idx == n-1) break;
                }
                ans = min(ans, count);
            }
        }
        int MOD = (int)1e9 + 7;
        if (ans < 0) ans += MOD;
        return ans == LLONG_MAX ? -1 : ans % MOD;
    }
};
