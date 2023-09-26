class Solution {
public:
    int dp[1001][1001];
    string longestPalindrome(string s) {
        int n = s.size();
        int ans = 0;
        string ret = "";
        int beg = 0, end = 0;
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                dp[i][j] = 0;
                if (i == j) {
                    dp[i][j] = 1;
                } else if (j - i == 1) {
                    if (s[i] == s[j]) {
                        dp[i][j] = 2;
                    } 
                } else {
                    if (s[i] == s[j]) {
                        dp[i][j] = dp[i+1][j-1] > 0 ? dp[i+1][j-1] + 2 : 0;
                    } 
                }
                if (dp[i][j] > ans) {
                    ans = dp[i][j];
                    beg = i;
                    end = j;
                }
            }
        }
        return s.substr(beg, end-beg+1);
    }
};
