class Solution {
public:
    int countHousePlacements(int n) {
        #define LL unsigned int
        vector<vector<LL>> dp(n+1, vector<LL>(4, 0));
        /*
        dp[i][0] = empty plot current
        dp[i][1] = one on top
        dp[i][2] = one on bottom
        dp[i][3] = both filled out
        */
        const LL MX = 1e9+7;
        dp[1][0]=dp[1][1]=dp[1][2]=dp[1][3]= 1;
        for (LL i = 2; i <= n; i++) {
            dp[i][0] = (dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3])%MX;
            dp[i][1] = (dp[i-1][0]+dp[i-1][2])%MX;
            dp[i][2] = (dp[i-1][0]+dp[i-1][1])%MX;
            dp[i][3] = (dp[i-1][0])%MX;
        }
        return (dp[n][0]+dp[n][1]+dp[n][2]+dp[n][3])%MX;
    }
};
