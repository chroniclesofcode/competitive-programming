class Solution {
public:
    int dp[2001];
    int distinctSubseqII(string s) {
        long long ans = 0;
        int md = 1e9 + 7;
        vector<long long> seen(26, 0);
        long long pref = 0;
        for (int i = 0; i < s.size(); i++) {
            long long c = s[i] - 'a';
            long long add = pref - seen[c] + 1;
            add %= md;
            pref += add;
            pref %= md;
            seen[c] += add;
            seen[c] %= md;
        }
        return (pref + md) % md;
    }
};
