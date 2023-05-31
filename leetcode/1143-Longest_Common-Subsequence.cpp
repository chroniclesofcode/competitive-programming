class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int ans = 0;
        int dp[1001][1001];

        for (int i = 0; i < text1.length(); i++) {
            for (int j = 0; j < text2.length(); j++) {
                if (text1[i] != text2[j]) {
                    if (i == 0 && j == 0) {
                        dp[i][j] = 0;
                    } else if (i == 0) {
                        dp[i][j] = dp[i][j-1];
                    } else if (j == 0) { 
                        dp[i][j] = dp[i-1][j];
                    } else {
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                } else {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                }
                ans = max(dp[i][j], ans);
            }
        }
        
        /*
        // Alternatively, this code can be written as
        
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                dp[i+1][j+1] = a[i] == b[j] ? dp[i][j] + 1 : max(dp[i][j+1], dp[i+1][j]);
            }
        }
        
        
        */
        return ans;
    }
};
