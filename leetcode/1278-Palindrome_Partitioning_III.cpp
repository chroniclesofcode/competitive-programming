class Solution {
public:
    /*
       Fairly difficult question, there are two parts to this DP.
       First, we calculate a range DP on the min num to convert
       i j into a palindrome, this is to ease the time complexity
       on the next step.
       Then we make a dp[k][i], where k is the splits left in the
       string, and from i which is the suffix.  At each step, we
       run a loop to calculate IF we split here, what is the
       min we can get. You have to make sure you adjust the inner
       loop properly, in our course j < n - k + 1, to make sure that
       we don't try to split 5 times when the subarray left is
       size 4 or less (we have to have enough spots to split). 

       The intuition isn't that easy, the DP recurrence is a pretty
       simple step but I struggled to realise I needed a range DP
       to do this calculation quickly.
    */
    int minc[101][101];
    int dp[101][101];
    int palindromePartition(string s, int kek) {
        int n = s.size();
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    minc[i][j] = 0;
                } else if (s[i] == s[j]) {
                    if (j-i == 1) {
                        minc[i][j] = 0;
                    } else {
                        minc[i][j] = minc[i+1][j-1];
                    }
                } else {
                    if (j-i == 1) {
                        minc[i][j] = 1;
                    } else {
                        minc[i][j] = minc[i+1][j-1] + 1;
                    }
                }
            }
        }
        // dp[k][i] = with k splits left for suffix starting at i
        for (int k = 1; k <= kek; k++) {
            for (int i = 0; i < n; i++) {
                if (k == 1) {
                    dp[k][i] = minc[i][n-1];
                } else {
                    int tmp = INT_MAX;
                    for (int j = i; j < n-k+1; j++) {
                        tmp = min(tmp, minc[i][j]+dp[k-1][j+1]);
                    }
                    dp[k][i] = tmp;
                }
            }
        }
        return dp[kek][0];
    }
};
