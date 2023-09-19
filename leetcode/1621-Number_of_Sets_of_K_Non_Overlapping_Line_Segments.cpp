class Solution {
public:
    const int MOD = (int)1e9 + 7;
    long long dp[1001][1001];
    long long pref[1001][1001];
    void debug(int sz, int k) {
        cout << "DP: " << endl;
        for (int i = 1; i < sz; i++) {
            for (int j = 1; j <= k; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        cout << "PREF:\n";
        for (int i = 1; i < sz; i++) {
            for (int j = 1; j <= k; j++) {
                cout << pref[i][j] << ' ';
            }
            cout << endl;
        }
    }
    int numberOfSets(int n, int k) {
        // How many ways we can fill up to gap n
        // with k lines.
        pref[0][1] = 1;
        dp[0][0] = 1;
        for (int i = 1; i < n; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i-1][j];  
                dp[i][j] += pref[i-1][j];
                dp[i][j] %= MOD;
                pref[i][j] += pref[i-1][j] + dp[i][j-1];
                pref[i][j] %= MOD;
            }
        }
        //debug(n, k);
        return (dp[n-1][k]) % MOD;
    }
};
