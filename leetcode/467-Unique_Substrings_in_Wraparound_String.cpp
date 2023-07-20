class Solution {
public:
    int dp[26];
    int findSubstringInWraproundString(string s) {
        // longest substring ending in s[i] store in DP
        dp[s[0]-'a'] = 1;
        int j = 0;
        for (int i = 1; i < s.size(); i++) {
            int cr = s[i] - 'a';
            int pr = s[i-1] - 'a';
            if (cr == (pr+1)%26) {
                dp[cr] = max(dp[cr], i - j + 1);
            } else {
                j = i;
                dp[cr] = max(dp[cr], 1);
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += dp[i];
        }
        return ans;
    }
};
