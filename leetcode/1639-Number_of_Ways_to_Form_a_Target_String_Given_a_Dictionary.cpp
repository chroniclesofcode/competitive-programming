class Solution {
public:
    long long dp[26][1001];
    long long sol[1001][1001];
    static const long long MOD = (long long)1e9 + 7;
    int numWays(vector<string>& words, string target) {
        long long mxw = words[0].size();
        for (auto word : words) {
            for (long long i = 0; i < mxw; i++) {
                long long ch = word[i] - 'a';
                dp[ch][i]++;
            }
        }
        // Num ways to make string[0..i] using only the
        // elements before 0..k
        long long ans = 0;
        for (long long i = 0; i < target.size(); i++) {
            long long ch = target[i] - 'a';
            for (long long j = 0; j < mxw; j++) {
                if (i == 0) {
                    if (j > 0) sol[i][j] = sol[i][j-1];
                    sol[i][j] += dp[ch][j];
                } else {
                    if (j > 0) sol[i][j] = sol[i][j-1];
                    if (i > 0 && j > 0)
                        sol[i][j] += sol[i-1][j-1] * dp[ch][j];
                }
                sol[i][j] %= MOD;
            }

        }
        return sol[target.size()-1][mxw-1];
    }
};
