class Solution {
public:
    static const int MX = 501;
    int dp[MX];
    int minOperations(string s1, string s2, int x) {
        /*
        find num of 1s, find num of 0s, parity of 0s and 1s will always stay the same
        so check if it's impossible
        Don't touch the stuff that's aligned properly. For every unaligned element,
        iterate through all 
        either take back one, or take a previous
        */
        int n = s1.size();
        int o1 = 0, o2 = 0, e1 = 0, e2 = 0;
        vector<int> diff;
        for (int i = 0; i < n; i++) {
            if (s1[i] == '0') o1++;
            else e1++;
            if (s2[i] == '0') o2++;
            else e2++;
            if (s1[i] != s2[i]) diff.push_back(i);
        }
        if (abs(e1-e2) % 2 == 1) return -1;
        const int INF = 1e9;
        int sz = diff.size();
        // either pair w adjacent behind, or pair one longer behind...
        for (int i = 1; i <= sz; i++) {
            dp[i] = dp[i-1] + x;
            if (i >= 2) dp[i] = min(dp[i], dp[i-2] + 2* (diff[i-1] - diff[i-2]));
        }
        return dp[sz] / 2;
    }
};
