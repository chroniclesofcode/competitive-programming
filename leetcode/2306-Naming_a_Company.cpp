class Solution {
public:
    int dp[26][26];
    long long distinctNames(vector<string>& ideas) {
        unordered_map<string, int> m;
        for (auto s : ideas) {
            m[s]++;
        }
        for (auto s : ideas) {
            int fch = s[0]-'a';
            for (int i = 0; i < 26; i++) {
                s[0] = i + 'a';
                if (!m[s]) dp[fch][i]++;
            }
        }
        long long ans = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = i+1; j < 26; j++) {
                ans += dp[i][j] * dp[j][i];
            }
        }
        return ans * 2;
    }
};
