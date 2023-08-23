class Solution {
public:
    int dp[30][1501];
    int lastStoneWeightII(vector<int>& stones) {
        int totsum = 0;
        int sum = 0;
        for (int i = 0; i < stones.size(); i++) {
            totsum += stones[i];
        }
        sum = totsum/2;
        for (int i = 0; i < stones.size(); i++) {
            for (int j = 0; j <= sum; j++) {
                if (i == 0) {
                    dp[i][j] = j >= stones[i] ? stones[i] : 0;
                    continue;
                }
                if (i > 0 && j >= stones[i]) {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-stones[i]] + stones[i]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return abs(totsum - 2*dp[stones.size()-1][sum]);
    }
};
