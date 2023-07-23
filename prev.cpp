class Solution {
public:
    int dp[26];
    int longestIdealString(string s, int k) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int ch = s[i] - 'a';
            int tmp = 0;
            for (int j = max(0, ch-k); j <= min(25, ch+k); j++) {
                tmp = max(tmp, dp[j]);
            }
            dp[ch] = max(dp[ch], tmp+1);
            ans = max(ans, dp[ch]);
        }
        return ans;
    }
};
