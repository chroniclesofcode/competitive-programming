class Solution {
public:
    /*
       Fairly easy idea, but I stumbled a bit on the implementation.
       You have to find LCS, then try to mush all the strings together
       while keeping the order of the LCS.

       I messed up a bit on the LCS indexings, I 1-indexed but my
       string comparisons were 0 indexed, so I had a small bug for a
       while. It's also interesting to note we are storing the LCS
       as a string, not as a number.

       On the mushing together bit, we just loop for both strings
       until we reach the common char - not the LCS will always
       be fully used up since it's the LCS - there is no case
       where there is remaining LCS at the end of the loop.
    */
    string dp[1001][1001];
    int ct[1001][1001];
    string shortestCommonSupersequence(string a, string b) {
        int n = a.size();
        int m = b.size();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + a[i-1];
                } else {
                    dp[i][j] = dp[i-1][j].size() > dp[i][j-1].size() ? dp[i-1][j] : dp[i][j-1];
                }
            }
        }
        string lcs = dp[n][m];
        string ret = "";
        int i = 0, j = 0;
        for (auto ch : lcs) {
            while (a[i] != ch) {
                ret += a[i];
                i++;
            }
            while (b[j] != ch) {
                ret += b[j];
                j++;
            }
            ret += ch;
            i++; j++;
        }
        ret += a.substr(i) + b.substr(j);
        return ret;
    }
};
