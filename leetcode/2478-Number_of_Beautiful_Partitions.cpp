class Solution {
public:
    long long dp[1001][1001];
    long long pp[1001];
    static const int md = (int)1e9 + 7;
    bool isp(char c) {
        return c == '2' || c == '3' || c == '5' || c == '7';
    }
    int beautifulPartitions(string s, int _k, int minLength) {
        int n = s.size();
        if (!isp(s[0])) return 0;
        // base case
        for (int i = 0; i < n; i++) if (i >= minLength && !isp(s[i])) dp[1][i] = 1;
        // finds prefix sum of primes
        int ct = 0;
        for (int i = 0; i < n; i++) {
            if (isp(s[i])) {
                ct++;
                if (i > 0 && isp(s[i-1])) ct--;
            }
            ct %= md;
            pp[i] = ct;
        }
        // main dp
        for (int k = 2; k <= _k; k++) {
            for (int i = 0; i < n; i++) {
                int last = i-minLength+1;
                if (k == 2) {
                    if (minLength <= last && !isp(s[i]))
                        dp[k][i] += pp[last]-pp[minLength-1];
                        dp[k][i] %= md;
                    continue;
                }
                dp[k][i] = i >= minLength ? dp[k][i-1] : 0;
                if (last > 0 && minLength <= last && isp(s[last]) && !isp(s[last-1])) {
                    dp[k][i] += dp[k-1][last-1];
                }
                dp[k][i] %= md;
            }
        }
        return dp[_k][n-1];
    }
};
