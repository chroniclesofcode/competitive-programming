class Solution {
public:
    // dp -> if I increment i to k, what is the total cost up to 0..i?
    static const int MX = (int)1e5 + 1;
    long long dp[MX][2];
    long long minIncrementOperations(vector<int>& nums, int k) {
        #define LL long long
        LL n = nums.size();
        LL INF = LLONG_MAX/2;
        for (int i = 0; i < nums.size(); i++) {
            LL cost = max(0, k - nums[i]);
            dp[i][0] = INF;
            dp[i][1] = INF;
            // 0 = don't set, 1 = set.
            if (i > 0)
                dp[i][0] = min(dp[i][0], dp[i-1][1]);
            if (i > 1)
                dp[i][0] = min(dp[i][0], dp[i-2][1]);
            if (cost == 0) {
                if (i <= 2)
                    dp[i][0] = 0;
                if (i > 2) 
                    dp[i][0] = min({dp[i][0], dp[i-3][1]});
            }
            if (i <= 2) 
                dp[i][1] = cost;
            if (i > 0)
                dp[i][1] = min({dp[i][1], dp[i-1][1]+cost});
            if (i > 1)
                dp[i][1] = min({dp[i][1], dp[i-2][1]+cost});
            if (i > 2)
                dp[i][1] = min({dp[i][1], dp[i-3][1]+cost});
            
        }
        return min(dp[n-1][0], dp[n-1][1]);
    }
};
