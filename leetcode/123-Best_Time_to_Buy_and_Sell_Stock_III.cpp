class Solution {
public:
    static const int mx = (int)1e5 + 1;
    int dp[mx][2];
    int maxProfit(vector<int>& prices) {
        int n = prices.size();   
        int msf = prices[0], mp = 0;
        for (int i = 0; i < n; i++) {
            mp = max(mp, prices[i] - msf);
            msf = min(msf, prices[i]);
            dp[i][0] = i > 0 ? max(dp[i-1][0], mp) : mp;
        }
        mp = 0, msf = prices[n-1];
        for (int i = n-1; i >= 0; i--) {
            mp = max(mp, msf - prices[i]);
            msf = max(msf, prices[i]);
            dp[i][1] = max(dp[i+1][1], i > 0 ? dp[i-1][0] + mp : mp);
        }
        return max(dp[n-1][0], dp[0][1]);
    }
};
