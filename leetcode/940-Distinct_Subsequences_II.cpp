class Solution {
public:
    int dp[2001];
    int distinctSubseqII(string s) {
        int md = 1e9 + 7;
        vector<int> seen(26, 0);
        for (int i = 0; i < s.size(); i++) {
            long long c = s[i] - 'a';
            long long ct = (seen[c] == 0);
            for (int j = i-1; j >= 0; j--) {
                ct += dp[j];
                ct %= md;
                if (s[j] == s[i]) break;
            }
            seen[c]++;
            dp[i] = ct;
        }
        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += dp[i];
            ans %= md;
        }
        return ans;
    }
};
